inherit ROOM;

void init()
{
	add_action("do_knock", "knock");
	add_action("do_push",  "push");
}
int is_open() {return stringp(query("exits/"+query("door_dir")));}
varargs void open_door(object ob)
{
	if (objectp(ob))
		set("exits/"+query("door_dir"),ob);
	else
	  set("exits/"+query("door_dir"),query("restroom"));
}
void close_door(){	delete("exits/"+query("door_dir"));}

int close_men()
{
	object room;

	room = find_object(query("restroom"));
	if(!objectp(room)) room = load_object(query("restroom"));
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
	else message("vision", "���ִ�����֪ͨ��ʦ�����.\n", room);
}

int do_knock(string arg)
{
	object room;

	if (is_open())
	return notify_fail(query("door_name")+"�Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "door" && arg != "men"))
	return notify_fail("��Ҫ��ʲô��\n");

	room = find_object(query("restroom"));
	if(! objectp(room) )
	room = load_object(query("restroom"));	

	if(objectp(room))
	{
		message("vision","���洫��һ��������������ŷ�����һ�ƣ���"+this_player()->query("name")+"һ��������վ�����⣬\n������Ҳ�������Ϣ��\n", room);
		if (room->query_sleeping_person() > 0)
		{
		message_vision(
"$N�����������һ���ţ����������洫��һ���������������\n"
"��Ȼ�������˯�ø������Ƶģ���ô�ö�û���ˡ�\n",
			this_player());
		}
		else if (room->query_inside_person() > 0)
		{
			switch( random(2) )
			{
				case 0:
				message_vision(
"$N������������ţ�ֻ�����������˺ܲ��ͷ��غ𵽣�\n"
"�������¾������ţ���˯���ˣ���������������\n",	this_player());
					break;
				case 1: 
					message_vision(
"$N������������ţ�ֻ����������Щ�춯��\n"
"����������������ȥ���ò��������Ƿ��š�\n", this_player());
					break;
			}	   	
		}
		else
		{
		message_vision("$N������������ţ��ˡ��ˡ��ˣ������ˡ��ˡ��ˣ�����\n",this_player());
		}
	}
	return 1;
}

int do_push(string arg)
{
	object room;

	if (is_open())
	return notify_fail("���Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "door" && arg != "men"))
	return notify_fail("��Ҫ��ʲô��\n");

	room = find_object(query("restroom"));
	if(! objectp(room) )
	room = load_object(query("restroom"));	
	
	if(objectp(room))
	{
		if( room->query_inside_person()<=0 )
		{
			open_door();
			message_vision("$N����ذ����ƿ���\n", this_player());
			room->open_door(__FILE__);
			remove_call_out("close_men");
			call_out("close_men", 10);
		}
		else 
		{
			message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",this_player());
		}
	}

	return 1;
}

string look_men()
{
	object room;

	if (is_open()) return (query("open_door_msg"));

	if(!objectp( room = find_object(query("restroom"))) )
	room = load_object(query("restroom"));

	if( objectp(room) && room->query_person_inside() > 0 )
		return (query("inside_msg"));
	return (query("no_one_msg"));
}


