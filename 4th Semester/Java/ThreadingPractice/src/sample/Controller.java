package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;

public class Controller {
    private Task<ObservableList<String>> task;

    @FXML private ListView FX_LV_list;

    public void initialize(){
        task = new Task<ObservableList<String>>() {
            @Override
            protected ObservableList<String> call() throws Exception {
                final ObservableList<String> temp = FXCollections.observableArrayList(
                        "Ishrak",
                        "Rizvi",
                        "Raiyan",
                        "Ishfar"
                );

                return temp;
            }
        };
        FX_LV_list.itemsProperty().bind(task.valueProperty());
    }

    @FXML private void handleButton(){
        new Thread(task).start();
    }
}
