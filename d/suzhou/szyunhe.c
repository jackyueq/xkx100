// Room: /d/suzhou/szyunhe.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
string look_sign();
int do_go(string);
inherit RIVER;

mapping *sign=({
	([	"name" : "����",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 200,
		"time" : 20
	]),
	([	"name" : "����",
		"id"   : "yz",
		"file" : "/d/city/matou",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "����",
		"id"   : "hz",
		"file" : "/d/hangzhou/matou",
		"value": 100,
		"time" : 10
	])
});

void create()
{
	::create();
	set("short", "�˺�");
	set("long", @long
�����ǹ��ϵ��˺ӵ���ͷ�ߣ�ֻ�������˺�(river) �������ʣ���
���ݳ��ﴩ�����˺ӵ������������ݵ�Ѱ�����ռң������ݵĳ������
��õĽ�ͨ���߾��Ǵ��ˡ�ֻ��������һλ�ϴ��򣬼����߹���������
����ӭ�������Ϲ���һ������(sign)��
long);
	set("exits",([
		"southeast" : __DIR__"xidajie1",
	]));
	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
		"sign" : (: look_sign :)
	]));
	set("coor/x", 830);
	set("coor/y", -1000);
	set("coor/z", 0);
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹���������Ů��һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ú��治Զ����������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵĲ���Ů˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "����Ů��̤�Ű��������������һ�㣬�������˺�ʻȥ��\n");
  set("leave_msg_in",   "����Ů��̤�Ű���������˵��һ��������ඡ������һ�㣬�������˺�ʻȥ��\n");
  set("come_msg_in",    "����Ů˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ����������һҶС�ۣ�Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ��ʮ����Ĳ���С������
�ֳ���ݣ����ڴ�β����ص��ۡ�
LONG );
                                   // �ɴ��ϵ�����
  set("to",         __DIR__"huzhongdao");  // �����յ� /*   ��ѡ   */
	setup();
}

void init()
{
	::init();
	add_action("do_go", "qu");
}

void do_move(object ob, int i)
{
//	ob->enable_player();
	ob->delete_temp("noliving");
	ob->delete_temp("block_msg/all");
	tell_object(ob, "�յ�վ���ˡ�\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), ob->name() + "�Ӵ�������������\n", ({ob}));
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");
	while(i--)
	{
		if (arg == sign[i]["id"])
		{
			switch (MONEY_D->player_pay(ob, sign[i]["value"]))
			{
				case 0:
					return notify_fail("��⵰��һ�ߴ���ȥ��\n");
				case 2:
					return notify_fail("����Ǯ��\n");
			}
			message_vision("$N������ȥ" + sign[i]["name"] + "�Ĵ���\n", ob);
//			ob->disable_player("<��;��>");
			ob->set_temp("noliving/journey", 1);
			ob->set_temp("block_msg/all", 1);
			ob->move(__DIR__"onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}
string look_sign()
{
	string str="�ɴ�ȥ(qu)��������ͷ��\n";
	int i=sizeof(sign);

	while (i--)
	{
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}

	return str;
}

