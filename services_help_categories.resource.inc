<?php

include_once 'services_help_categories.vo.inc';

function _services_help_categories_retrieve($term) {

  $result = new HelpArticle($term);   
  $termByName = (object) taxonomy_get_term_by_name($result->term);  
  $result->content = _services_help_categories_serialize_data($termByName); 
  return $result;
}

function _services_help_categories_serialize_data($data) {
	
	$result = array();	
	
	foreach ($data as $k => $v) { 	
		
		$tid = $v->tid;	
		
		$nodeIdByTid = taxonomy_select_nodes($tid);	
		$items = entity_load('node', $nodeIdByTid);
			
		foreach ($items as $key => $value){
			$result[$value->vid]->node->nodeId = $value->vid;
			$result[$value->vid]->node->cobolName = $value->field_cobol[und][0][value];
			$result[$value->vid]->node->title = $value->title;			
			$result[$value->vid]->node->description = $value->body[und][0][value];	
		}      
	}
	return $result;
  
}