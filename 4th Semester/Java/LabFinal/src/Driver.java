import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class Driver {
    public static void main(String[] args) {
        // Put username and password here!
        UserInterface obj = new UserInterface("Ishrak", "dragonsword05");
        obj.DrawDataView();
    }
}

class UserInterface {
    JDBC Account;

    public UserInterface(String Username, String Password){
        Account = new JDBC(Username, Password);
    }

    private JTextField TF_ID;
    private JFrame F_Entry;
    private JTextField TF_Name;
    private JTextField TF_Country;
    private JButton B_Add;
    private JLabel L_ID;
    private JLabel L_Name;
    private JLabel L_Country;
    private JButton B_Cancel;

    public void DrawDataEntry(){
        L_ID = new JLabel("ID");
        L_ID.setBounds(50, 50, 50, 25);


        L_Name = new JLabel("Name");
        L_Name.setBounds(50, 100, 50, 25);


        L_Country = new JLabel("Country");
        L_Country.setBounds(50, 150, 50, 25);


        B_Add = new JButton("Add");
        B_Add.setBounds(100, 200, 100, 50);
        B_Add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Integer x = Account.insertStudentInfo(
                        TF_ID.getText(),
                        TF_Name.getText(),
                        TF_Country.getText()
                );

                if (x == -1){
                    System.out.println("COultn't add");
                }
                else{
                    System.out.println("ADDED!");
                }
            }
        });


        TF_ID = new JTextField("Input ID");
        TF_ID.setBounds(200, 50, 100, 25);
        TF_ID.setVisible(true);


        TF_Name = new JTextField("Input Name");
        TF_Name.setBounds(200, 100, 100, 25);


        TF_Country = new JTextField("Input Country");
        TF_Country.setBounds(200, 150, 100, 25);


        F_Entry = new JFrame("Data entry");
        F_Entry.setLayout(null);
        F_Entry.setVisible(true);
        F_Entry.setSize(500, 300);
        F_Entry.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        F_Entry.add(L_ID);
        F_Entry.add(L_Name);
        F_Entry.add(L_Country);
        F_Entry.add(B_Add);
        F_Entry.add(TF_ID);
        F_Entry.add(TF_Name);
        F_Entry.add(TF_Country);
    }

    private JFrame F_View;
    private JTextField TF_GPA;
    private JButton B_Search;
    private JLabel L_GPA;
    private JLabel SL_Name;
    private JLabel SL_GPA;

    public void DrawDataView(){
        L_ID = new JLabel("ID");
        L_ID.setBounds(50, 50, 50, 25);

        L_Name = new JLabel("Name");
        L_Name.setBounds(50, 100, 50, 25);

        L_GPA = new JLabel("GPA");
        L_GPA.setBounds(50, 150, 50, 25);

        SL_Name = new JLabel("Name");
        SL_Name.setBounds(200, 100, 100, 25);

        SL_GPA = new JLabel("GPA");
        SL_GPA.setBounds(200, 150, 100, 25);

        B_Search = new JButton("Search");
        B_Search.setBounds(100, 200, 100, 50);
        B_Search.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String SID = TF_ID.getText().trim();
                if (SID.length() > 0){
                    try{
                        double sum = 0.0;
                        int i = 0;

                        ResultSet rs = Account.viewStudentInfo(SID);

                        if (rs != null){
                            while(rs.next()){
                                SL_Name.setText(rs.getString(1));
                                sum += rs.getDouble(2);
                                ++i;
                            }
                            Double d = (sum/i);
                            SL_GPA.setText(d.toString());
                        }
                        else{
                            SL_Name.setText("N/A");
                            SL_GPA.setText("N/A");
                        }

                        System.out.println("Search successfull!");

                        rs.close();
                    }
                    catch(SQLException se){
                        se.printStackTrace();
                    }
                }
            }
        });

        B_Cancel = new JButton("Cancel");
        B_Cancel.setBounds(200, 200, 100, 50);
        B_Cancel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                F_View.dispose();
            }
        });

        TF_ID = new JTextField("Input ID");
        TF_ID.setBounds(200, 50, 100, 25);
        TF_ID.setVisible(true);

        F_View = new JFrame("Data view");
        F_View.setLayout(null);
        F_View.setVisible(true);
        F_View.setSize(500, 300);
        F_View.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        F_View.add(L_ID);
        F_View.add(L_Name);
        F_View.add(L_GPA);
        F_View.add(SL_Name);
        F_View.add(SL_GPA);
        F_View.add(B_Search);
        F_View.add(B_Cancel);
        F_View.add(TF_ID);
    }
}

class JDBC {
    private Statement statement;
    private String dbURL;
    private Connection connection;
    private String query;
    private ResultSet rs;

    public JDBC(String Username, String Password){
        try{
            dbURL = "jdbc:oracle:thin:@localhost:1521:xe";
            String ClassName = "oracle.jdbc.OracleDriver";
            Class.forName(ClassName);

            connection = DriverManager.getConnection(dbURL, Username, Password);

            if (connection != null){
                System.out.println("Connection successful");
                statement = connection.createStatement();
            }
        }
        catch(SQLException | ClassNotFoundException e){
            e.printStackTrace();
        }
    }

    public Integer insertStudentInfo(String SID, String Name, String Country){
        query = "INSERT INTO Students VALUES(" + SID + ",'" + Name + "','" + Country + "')";
        return runUpdate();
    }

    public ResultSet viewStudentInfo(String ID){
        query = "SELECT S.Name, R.GPA FROM Students S, Results R WHERE S.ID = R.StudentID AND S.ID=" + ID;
        return runQuery();
    }


    private ResultSet runQuery(){
        try{
            rs = statement.executeQuery(query);
            return rs;
        }
        catch (SQLException e){
            e.printStackTrace();
        }
        return null;
    }

    private Integer runUpdate(){
        try{
            return statement.executeUpdate(query);
        }
        catch (SQLException e){
            e.printStackTrace();
        }

        return -1;
    }
}


/*
CREATE TABLE Students(
    ID Number,
    Name VARCHAR2(50),
    Country VARCHAR2(50),
    CONSTRAINT PK_ID PRIMARY KEY (ID)
);

CREATE TABLE Results(
    Semester VARCHAR2(10),
    CourseID NUMBER,
    StudentID NUMBER,
    GPA NUMBER,
    CONSTRAINT FK_ID FOREIGN KEY (StudentID) REFERENCES Students
);

INSERT INTO Students VALUES(1, 'Omar', 'Bangladesh');
INSERT INTO Students VALUES(2, 'Farabi', 'Bangladesh');
INSERT INTO Students VALUES(3, 'Mashfi', 'Bangladesh');
INSERT INTO Students VALUES(4, 'Sabik', 'Bangladesh');

INSERT INTO Results VALUES('Summer', 1, 1, 3.8);
INSERT INTO Results VALUES('Summer', 1, 1, 3.4);
INSERT INTO Results VALUES('Summer', 1, 2, 4.0);
INSERT INTO Results VALUES('Summer', 1, 3, 3.4);
INSERT INTO Results VALUES('Summer', 1, 4, 3.1);

SELECT S.Name, R.GPA FROM Students S, Results R WHERE S.ID = R.StudentID AND S.ID=1;
 */