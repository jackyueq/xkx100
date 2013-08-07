// Room: /d/baituo/storeroom.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void init();
int do_open(string);
string* obj = ({
	"/d/xingxiu/obj/fire",
	"/d/xingxiu/obj/hulu",
	"/clone/book/bt_book1",
	"/clone/book/bt_book2",
	"/clone/book/bt_book3",
	"/clone/book/bt_book5",
	"/d/baituo/obj/shepi1",
//	"/d/baituo/obj/yao",
//	"/d/baituo/obj/yao1",
//	"/d/baituo/obj/yao2",       
});

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������ң������ܲ�͸�硣��һ���ű��ŵ�һ��ùζ������
����������������ҫ�£��㿴���������ݵĻҳ����ɶѳɶѵ���Ʒ��
���������䷿�䡣��������Ϊʲô�������뿪ʱ������Щ��ƷҲ���ߡ�
ֻ�йر��ŵĴ���(door)��
LONG	);
	set("item_desc" , ([
		"door" : "һ��ľ�ţ�Ҳ���ܴ򿪡�\n",
	]) );
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("coor/x", -50000);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_open","open");
	add_action("do_find", "find");
	add_action("do_find", "zhao");
	add_action("do_find", "fan");
}

int do_open(string arg)
{
	object me=this_player();
	object room;

	if( me->is_busy()) return notify_fail("����æ���أ�û�ֿ��š�\n");
	if( !arg|| arg!="door") return notify_fail("��Ҫ��ʲô��\n");
	if(!( room = find_object(__DIR__"kongdi")) )
		room = load_object(__DIR__"kongdi");
	if(!objectp(room)) return notify_fail("ERROR:not found 'kongdi.c' \n");
	if(room->query_temp("lock")==1)
		return notify_fail("���Ѿ���������ס�ˡ�\n");
	message_vision("$N�����ƿ��ţ����˳�ȥ�����ְ�������������\n",me);
	message("vision", "�������˳��������ְ��������ˡ�\n",room);
	me->move(room);
	return 1;
}

int do_find()
{
	object me, ob;
	me = this_player();
	if( (int)me->query_temp("baituo_find") ) 
		return notify_fail("���Ѿ����ֶ����ˣ����˾��߰ɡ�\n");
	if (me->query_skill("hamagong", 1) > 10 &&
		me->query_skill("xidu-poison", 1) > 30)
	{
		message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
		remove_call_out("found");
		call_out("found", 1, me);    
		return 1;
	}
	if (me->query_skill("xidu-poison", 1) < 50)
	{
		message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
		if(random((int)me->query("kar")) < 15)
		{
			write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ�\n");
			me->unconcious();
			return 1;
		}
		else
		{
			remove_call_out("found");
			call_out("found", 1, me);    
			return 1;
		}
	}
	else
	{ 
		message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
		write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ������ã����ж��ˣ�\n");
		me->apply_condition("snake_poison", 22);
		me->unconcious();
		return 1;
	}
}

int found(object me)
{
	object ob;
	ob = new(obj[random(sizeof(obj))] );
	ob->move(environment(me));
	message_vision("$N���˰��죬�ҵ���"+ob->query("name")+"��\n", me);
	me->set_temp("baituo_find", 1);
	return 1;
}

