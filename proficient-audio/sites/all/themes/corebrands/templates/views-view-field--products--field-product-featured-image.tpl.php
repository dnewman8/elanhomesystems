<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

$image_data = '';
if (!empty($row->field_field_product_featured_image)) {
    $image_data = $row->field_field_product_featured_image[0]['rendered'];
}
elseif (!empty($row->field_field_product_image)) {
    $image_data = $row->field_field_product_image[0]['rendered'];
}

if (!empty($image_data) && isset($row->node_title)) {
    $image_data['#item']['alt'] = $row->node_title;
}

?>

<?php if (!empty($image_data)): ?>
      <?php print render($image_data); ?>
<?php endif; ?>


