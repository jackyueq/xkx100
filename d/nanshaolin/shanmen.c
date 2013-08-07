// Room: /d/nanshaolin/shanmen.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
ת��ɽ�꣬��Ŀ��ȥ��ɽ����һ��Ƭ���ݶ��Ǳ��߻�ǽ��ȴ��һ��
����֡�����ǰ̧ͷһ������ɽ��(gate)���н���д�š����ֹ�ɲ����
�����֡�ԭ����������������¡�����������������ɽ��Ժ�����Ϸ���
��������Ժ���书����ɽ����һ���ഫ������ɮ���书֮ǿ��������ɽ
���¡�
LONG );
	set("outdoors", "nanshaolin");
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/yuantong" : 1,
		CLASS_D("nanshaolin")+"/fangqiong" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"guangchang",
	]));
	set("coor/x", 1820);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
//	"/clone/board/nanshaolin_b"->foo();
}

void init()
{
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","ƹ��һ�����������˰Ѵ��Ź����ˡ�\n",this_object());
		room->delete("exits/south");
		if (objectp(present("yuan tong", room)))
			message("vision","Ԫʹ��ǰ�Ѵ��Ź���������\n",room);
		else message("vision","׳��ɮ����ǰ�Ѵ��Ź���������\n",room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
	object room;

	if (query("exits/north")) return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"gchang-1")) )
		room = load_object(__DIR__"gchang-1");
	if(objectp(room))
	{
		set("exits/north", __DIR__"gchang-1");
		message_vision("$N������������ţ�ֻ��֨��һ����һλ׳��ɮ��Ӧ���򿪴��ţ�\n����������Ŀ���������´�����$N��\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision","���洫��һ����������׳��ɮ��Ӧ����ǰ�Ѵ��ſ���\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" )
	{
		return ::valid_leave(me, dir);
	}
	if ( (me->query("family/family_name") == "������") ||
		(me->query("family/family_name") == "��������"))
	{
		if (((int)me->query("guilty") == 0) &&
			((int)me->query("K_record") == ((int)me->query("PKS") + (int)me->query("MKS"))))
		{
			message_vision("׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n", me);
			return 1;
		}
		else
		{
			if((int)me->query("guilty") == 0)
			{
				if((int)me->query("shen_record") >
					(int)me->query("shen"))
					me->set("guilty", 1);
				else me->set("guilty", 2);
				me->set("K_record", me->query("PKS") + me->query("MKS"));
				me->set("shen_record", me->query("shen"));
			}
			write("׳��ɮ�˳���������˵��������Ժ���ִ���ʦ��ʦ��\n����ȥ����Ժ�������й�����\n");
			return 1;
		}
	}
	else if( present("yingxiong ling", me) )
		{
			message_vision("׳��ɮ�˺�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n", me);
			return 1;
		}
    
	if (me->query("shen") >= 0)
	{
		if (me->query("gender") == "Ů��")
		{
			return notify_fail("׳��ɮ��˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�\n");
		}
		else
		{
			return notify_fail("׳��ɮ��˵������λʩ����ذգ����²��Ӵ����ˡ�\n");
		}
	}

	return notify_fail("׳��ɮ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n�Ժ��ٸ��߽�����һ��������ʱ��ն�����ǵĹ��ȣ�\n");
}

string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
