inherit ROOM;

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
	remove_call_out("force_open");
	call_out("force_open",300);
}

int is_open() {return stringp(query("exits/"+query("door_dir")));}
varargs void open_door(object ob)
{
	if (objectp(ob))
		set("exits/"+query("door_dir"),ob);
	else
	  set("exits/"+query("door_dir"),query("outroom"));
}
void close_door(){	delete("exits/"+query("door_dir"));}
int query_inside_person()
{
	object *inv;
	int i,count;
	
	inv = all_inventory();
	count = 0;
	for (i=0;i<sizeof(inv);i++)
		if (userp(inv[i])) count++;
	
	return count;
}
int query_sleeping_person()
{
	object *inv;
	int i,count;
	
	inv = all_inventory();
	count = 0;
	for (i=0;i<sizeof(inv);i++)
		if (userp(inv[i]) && inv[i]->query_temp("noliving/sleeped")) count++;
	
	return count;
}

void close_men()
{
	object room;

	if(!objectp( room = find_object(query("outroom")) ))
		room = load_object(query("outroom"));
	if(objectp(room))
	{
		if (  is_open() ) 
		{
			close_door();
			message("vision", query("door_name")+"֨֨ѽѽ���Լ������ˡ�\n", this_object());
			room->close_door();
			message("vision", query("door_name")+"֨֨ѽѽ���Լ������ˡ�\n", room);
		}
	}
}

int do_close(string arg)
{
	if ( !is_open() )
		return notify_fail("���Ѿ��ǹ��ŵ��ˡ�\n");

	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N����Ź��ϡ�\n", this_player());

	remove_call_out("close_men");
	call_out("close_men", 0);

	return 1;
}

int do_open(string arg)
{
	object room;
	object me = this_player();

	if (is_open())
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "men" && arg != "door" && arg != query("door_dir")))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!objectp( room = find_object(query("outroom"))) )
		room = load_object(query("outroom"));
	if(objectp(room))
	{
		open_door();
		message_vision("$N������ŵذ��Ŵ򿪡�\n", this_player());
		room->open_door(__FILE__);
		
		if (me->query_temp("sleeped"))
		message("vision", "֨��һ����"+me->query("name")+"��������ش�������Ŵ��ˡ�\n",room);
		else
		message("vision", "���һ����"+me->query("name")+"��������Ŵ򿪣�һ���Ĳ��ͷ���\n",room);
		
		remove_call_out("close_men");
		call_out("close_men", 10);
	}

	return 1;
}

int force_open()
{
	object room;
	if(!objectp( room = find_object(query("outroom"))) )
		room = load_object(query("outroom"));
	if( !objectp(room) )	return 0;
	if( query_inside_person() <= 0 )	return 0;
	
	open_door();
	room->open_door(__FILE__);
	message("vision","����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\n"+query("force_name")+"ž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ����ʲô��\n", room);
	remove_call_out("close_men");
	call_out("close_men", 10);
}