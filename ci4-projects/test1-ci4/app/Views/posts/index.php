Hello world!

<?php
if(!empty($posts)){
    echo '<h1>Posts List<h1>';
    foreach($posts as $posts_item){
        echo'<a href="/PostController/show/'.$posts_item['id'].'">'.$posts_item['title'].'</a><br>';
    }
}
?>