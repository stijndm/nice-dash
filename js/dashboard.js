Drupal.behaviors.nicedDash = function(){
  initFilters();
  function initFilters(){
    $('.filter-container').remove();
    $('.view-filters form').before('<div class="filter-container"><div class="clear-block"><a href="" class="toggle-link">Toggle filter</a></div></div>');
    $('.view-filters form').hide();
    $('.toggle-link').bind('click', toggleFilters);
  }
  function toggleFilters(e){
    $(e.target).parent().parent().siblings('form').slideToggle();
    e.preventDefault();
  }
}