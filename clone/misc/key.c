// key.c
#include <ansi.h>
inherit ITEM;
int is_key() {return 1;}

void create()
{
	set_name("˽��Կ��", ({"key", "yaoshi"}));
	set("long",
		"����һ���һ���˽��סլ��Կ�ס�
������������(unlock)�͹���(lock)��\n");
	set("unit", "��");
	set("weight", 10);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
}

string query_autoload() { return 1 + ""; }	//autoload weapon
void init()
{
        add_action("do_lock","lock");
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object table, bottle, rose, room, here, me = this_player();
  object *rooms;
  int i;
  if (!present(this_object(), this_player()))
    return 0;

	if (!me->query("home"))
		return notify_fail("��û˽լѽ�����⿪ʲô����\n");
	if ((string)environment(me)->query("short")!="�һ�ƺ")
		return notify_fail("���˽լ���һ������һ�ƺ�ϣ�\n");
	rooms = children("/d/taohuacun/obj/player");
	for (i=0;i < sizeof(rooms);i++)
	{
		if (rooms[i]->query("owner")==me->query("id"))
		 {room=rooms[i];break;}
	}
	if (i == sizeof(rooms))
	{
		seteuid(getuid());
		room = new("/d/taohuacun/obj/player");
	  room -> set("short", me->query("home/home_name"));
	  room -> set("long", me->query("home/home_desc")+"\n");
    room -> set("owner",me->query("id"));
	  table = new("/d/taohuacun/obj/table");
	  bottle = new("/d/taohuacun/obj/bottle");
	  rose = new("/d/taohuacun/obj/rose");
	  rose -> move(bottle);
	  bottle -> move(table);
	  table -> move(room);
	}
	  if(!( here = find_object("/d/taohuacun/taohua5")) )
		  here = load_object("/d/taohuacun/taohua5");
	  here->set("exits/enter", file_name(room) );
	  room->set("exits/out", "/d/taohuacun/taohua5" );
//        set("sleep_room", "1");
	room->set("sleep_room","1");
	message_vision(HIG "$N�ͳ�Կ�ף�����һ���������ƿ����š�\n" NOR,me);
	return 1;
}
int do_lock()
{
	object here;
  object me=this_player();
  object room;
  int i,flag;
  object *inv;
  if (!present(this_object(), this_player()))
    return 0;
	if ((string)environment(me)->query("owner")!=me->query("id")
	 && (string)environment(me)->query("short")!="�һ�ƺ")
		return notify_fail("���˽լ���һ������һ�ƺ�ϣ�\n");

	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	if ( here->query("exits/enter") && 
	room = find_object(here->query("exits/enter")))
	{
	 	flag=1;
	 	inv=all_inventory(room);
	 	for(i=0;i<sizeof(inv);i++)
	 	 {
	 	 	  if (userp(inv[i]))
	 	 	  {flag=0;break;}
	 	 	}
	 	 if (flag) destruct(room);
	here->delete("exits/enter");
	message_vision(HIG "ֻ��������һ���죬$N�ѷ��Ź����ˡ�\n" NOR, this_player());
	}
	else
	{return notify_fail("��û�п��Ű���\n");}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
