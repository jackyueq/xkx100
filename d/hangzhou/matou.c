// Room: /d/hangzhou/matou.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
string look_sign();
int do_go(string);
inherit ROOM;

mapping *sign=({
	([	"name" : "����",
		"id"   : "sz",
		"file" : "/d/suzhou/szyunhe",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "����",
		"id"   : "yz",
		"file" : "/d/city/matou",
		"value": 200,
		"time" : 20
	]),
	([	"name" : "����",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 300,
		"time" : 30
	])
});

void create()
{
	set("short", "�ٰ���ͷ");
	set("long", @long
�����ǹ��ϵ��˺ӵ��յ㣬�˺�����ɽ���µĵ۶����£��ᴩ�й�
�Ļ�����ƽԭ�����ຣ�ӡ��ƺӡ����ӡ�������Ǯ�������ˮϵ��ֹ��
�ų����ú�����֮��ĺ��ݳǡ��˺�������������������Ӱ�����ϵķ�
��Ĳ������˹���������ԴԴ���ϡ�
    ���߽���ͷ���Ϳ���һλ�ϴ���վ�ڴ��ߣ����ϸ߾���һ��д����
��ľ��(sign)��
long);
	set("exits",([
		"southwest" : __DIR__"road9",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
	set("coor/x", 4200);
	set("coor/y", -1430);
	set("coor/z", 0);
	set("outdoors", "xihu");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_go", "qu");
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
			ob->move("/d/suzhou/onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}

