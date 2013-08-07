
inherit NPC;

void  create()
{
	set_name("С��",({"changer"}));
	setup();
}	

int  do_list()
{
	string *goods;
	int i;
	
	if ( !arrayp(goods=this_object()->query("exchangeable_goods")) || !sizeof(goods) )
		return notify_fail( "Ŀǰû�пɽ����Ķ�����\n" );
			
	printf( "�������%s����������Ʒ��\n", query("name") );
	for ( i = 0; i < sizeof(goods); i++ )
	  printf( "%s\n", goods[i]->short() );
	return 1;
}	

int do_change( string arg )
{
	object me=this_player();
	object ob1,ob2;
	string *str, *wgoods, *egoods;
	int i;
	
	if (!stringp(arg))
		return notify_fail( "��Ҫ��ʲô����\n" );
	str = explode( arg, " " );
	if ( sizeof( str ) != 3  || str[1] != "to" )
		return notify_fail( "�����ʽ�ǣ�change sth. to sth.\n" );
	if ( !objectp( ob1 = present(str[0],me) ) )
		return notify_fail( "������û������������\n" );					
	egoods = query( "exchangeable_goods" );		
	if ( !arrayp(egoods) )
		return notify_fail( "Ŀǰ��û����Ʒ�ɹ�������\n" );
	wgoods = query( "want_goods" );
	if ( !arrayp(wgoods) )
		return notify_fail( "��������Ҫʲô������\n" );		
	for ( i = 0; i < sizeof(wgoods); i++ )
	  if ( wgoods[i]->query("id") == str[0] )  break;
	if ( i >= sizeof(wgoods) )
		return notify_fail( "��������Ҫ����������\n" );
	for ( i = 0; i < sizeof(egoods); i++ )
	  if ( egoods[i]->query("id") == str[2] )  break;
	if ( i >= sizeof(egoods) )
		return notify_fail( "��û�������������㽻����\n" );
	ob2 = new( egoods[i] );
	message_vision( "$N�ó�һ" + ob1->query("unit") + ob1->query("name") + 
			"��" + query("name") + "����һ" + ob2->query("unit") + ob2->query("name") + "��\n", me );
	destruct( ob1 );
	ob2->move( me );
	return 1;
	
}