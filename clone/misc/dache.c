// Last Modified by Winder on May. 15 2001
// /clone/misc/dache.c
// sign/value���������ٵ���

inherit ITEM;
#include <ansi.h>;
int do_go(string);
int look_sign();
mapping *sign=({
	([	"name"   : "��ľ��",
		"target" : "��ľ����ʯ��",
		"id"     : "heimuya",
		"out"    : "heimuya",
		"file"   : "/d/heimuya/road1",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "���Ʒ�",
		"target" : "���Ʒ�ɽ����",
		"id"     : "tiezhang",
		"out"    : "tiezhang",
		"file"   : "/d/tiezhang/shanjiao",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "÷ׯ",
		"target" : "÷ׯ����",
		"id"     : "meizhuang",
		"out"    : "meizhuang",
		"file"   : "/d/meizhuang/gate",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "̫��",
		"target" : "̫������",
		"id"     : "taihu",
		"out"    : "yanziwu",
		"file"   : "/d/yanziwu/hupan",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ��",
		"id"     : "wuliang",
		"out"    : "wuliang",
		"file"   : "/d/wuliang/shanlu6",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽɽ·",
		"id"     : "tianshan",
		"out"    : "xiyu",
		"file"   : "/d/xingxiu/tianroad2",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ʯ��",
		"id"     : "lingxiao",
		"out"    : "lingxiao",
		"file"   : "/d/lingxiao/shiya",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "ѩɽ��",
		"target" : "ѩɽ��ɽ��",
		"id"     : "xueshan",
		"out"     : "xueshansi",
		"file"   : "/d/xueshan/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ɽ��",
		"id"     : "mingjiao",
		"out"    : "mingjiao",
		"file"   : "/d/mingjiao/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ����",
		"id"     : "zhongtiao",
		"out"    : "zhongtiao",
		"file"   : "/d/huashan/jzroad3",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ�׺�",
		"id"     : "changbai",
		"out"    : "changbai",
		"file"   : "/d/guanwai/baihe",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "����ɽ����",
		"id"     : "zhongnan",
		"out"    : "zhongnan",
		"file"   : "/d/quanzhen/shanjiao",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ����Ͽ",
		"id"     : "hengshan",
		"out"    : "hengshan",
		"file"   : "/d/hengshan/jinlongxia",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ������",
		"id"     : "henshan",
		"out"    : "henshan",
		"file"   : "/d/henshan/lingxingmen",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽɯ��ƺ",
		"id"     : "huashan",
		"out"    : "huashan",
		"file"   : "/d/huashan/shaluo",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "̩ɽ",
		"target" : "̩ɽ��ڷ�",
		"id"     : "taishan",
		"out"    : "taishan",
		"file"   : "/d/taishan/daizong",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��ɽ",
		"target" : "��ɽ̫����",
		"id"     : "songshan",
		"out"    : "songshan",
		"file"   : "/d/songshan/taishique",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "���ɽ",
		"target" : "��ǽ�����",
		"id"     : "qingcheng",
		"out"    : "qingcheng",
		"file"   : "/d/qingcheng/jianfugong",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "����ɽ",
		"target" : "������ɽ��",
		"id"     : "kunlun",
		"out"    : "kunlun",
		"file"   : "/d/kunlun/shanmen",
		"value"  : 300,
		"time"   : 10
	]),
	([	"name"   : "��üɽ",
		"target" : "��ü������",
		"id"     : "emei",
		"out"    : "emei",
		"file"   : "/d/emei/bgs",
		"value"  : 200,
		"time"   : 10
	]),
	([	"name"   : "�䵱ɽ",
		"target" : "�䵱�⽣��",
		"id"     : "wudang",
		"out"    : "wudang",
		"file"   : "/d/wudang/jiejianyan",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "��������",
		"target" : "������ӭ��ͤ",
		"id"     : "nanshaolin",
		"out"    : "nanshaolin",
		"file"   : "/d/nanshaolin/ting",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "������",
		"target" : "������ɽ��",
		"id"     : "shaolin",
		"out"    : "shaolin",
		"file"   : "/d/shaolin/shanmen",
		"value"  : 100,
		"time"   : 10
	]),
	([	"name"   : "����",
		"target" : "��������㳡",
		"id"     : "yangzhou",
		"out"    : "yangzhouw",
		"file"   : "/d/city/shilijie4",
		"value"  : 100,
		"time"   : 10
	]),
});
void setup()
{}
void init()
{
	add_action("do_go", "qu");
	add_action("look_sign", "kan");
}
void create()
{
	set_name("��", ({"da che", "che", "dache"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","����һ�����²��ɵĴ󳵣���������һ�����ϲ��ϵĳ���
�������ϸ����(kan)���Ϲ��ŵ����ӣ��Ǿ�������ϴ󳵣�\n����ȥ(qu)�ĵط���\n");
		set("unit", "��");
		set("no_fight",1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("no_drop", 1);
		set("no_put", 1);
	}
	setup();
}
int look_sign()
{
	string adjstr1, adjstr2, str="�ɴ�ȥ(qu)�����еط���\n  Ŀ�ĵ�        ����          ����\n================================================\n";
	int adj1, adj2, i=sizeof(sign);
	while (i--)
	{
		if(environment(this_player())->query("outdoors")!=sign[i]["out"])
		{
			str += " "+sign[i]["target"];
			adjstr1 = sign[i]["target"];
			adj1 = 18-strlen(adjstr1);
			while (adj1--) str += " ";
			str += "("HIY + sign[i]["id"] + NOR") ";
			adjstr2 = "(" + sign[i]["id"] + ") ";
			adj2 = 18-strlen(adjstr2);
			while (adj2--) str += " ";
			str += "��"CYN+MONEY_D->price_str(sign[i]["value"]) + NOR"\n";
		}
	}
	write(str+"------------------------------------------------\n");
	return 1;
}

void do_move(object ob, int i)
{
	ob->delete_temp("block_msg/all");
	ob->delete_temp("noliving");
	write("���ڵ�"+sign[i]["name"]+"�ˡ�\n\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), "\n��ȻԶ����һ���󳵷ɳ۶������쵽�����ʱ������ͣ��������\n" + ob->name() + "�Ӵ�������������\n", ({ob}));
}

int do_go(string arg)
{
	object *inv, ob=this_player();
	int j, i=sizeof(sign);

	if (!arg) return notify_fail("��Ҫȥ����ȿ���(kan)���߰ɣ�\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");

	inv = all_inventory(ob);
	for (j = 0; j < sizeof(inv); j++)
	{
		if (inv[j]->is_character())
		{
			write("������λ�����ޣ���������ô���ˡ�\n");
			return 1;
		}
	}
	 if (  ob->query_temp("LAST_PKER_TIME") && 
             time() - ob->query_temp("LAST_PKER_TIME")<7200 && !wizardp(ob))
             return notify_fail("ɱ���ˣ��ɲ�������ͷ�ڹ꣡\n");

	while(i--)
	{
		if (arg == sign[i]["id"])
		{
			if(environment(ob)->query("outdoors") == sign[i]["out"])
				return notify_fail("����Ц����������Ϳ����ȥʲôȥ���㲻���Ѿ���"HIR+ sign[i]["name"] +NOR"���𣿣���\n");
			switch (MONEY_D->player_pay(ob, sign[i]["value"]))
			{
				case 0:
					return notify_fail("��⵰��һ�ߴ���ȥ��\n");
				case 2:
					return notify_fail("����Ǯ��\n");
			}
			message_vision("\n$N�����˴󳵣�һ���ֶ���" + chinese_number(sign[i]["value"]/100) + "�����Ӹ�����˵��������ȥ" +sign[i]["name"]+ "����\n$N˵���ƿ����ӣ�һ���������ȥ��\n\n", ob);
			write(HIC"����"NOR" -
    ����ɸɾ�����������������Ĵ����ӡ����������������������
��϶��͸���������⿴�����ľ��£��е�׳�ۣ��е�Ҳ��Ȥ�����ǻ��
������˯ȥ��Ҳ����·�����˶�á��������һ�����壬���������š�
��������ǰ�棬һ·������һ·����غ���ʲôС����\n");
			ob->set_temp("noliving/journey", 1);
			ob->set_temp("block_msg/all", 1);
			ob->move("/clone/misc/dachenei");
			call_out("do_move", sign[i]["time"]+random(10), ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}
/*
������ɽ��   (shaolin)    /d/shaolin/shanmen
�䵱�⽣��   (wudang)     /d/wudang/jiejianyan
��ü������   (emei)       /d/emei/bgs
������ɽ��   (kunlun)     /d/kunlun/shanmen
��ǽ�����   (qingcheng)  /d/qingcheng/jianfugong
��ɽ̫����   (songshan)   /d/songshan/taishique
̩ɽ��ڷ�   (taishan)    /d/taishan/daizong
��ɽɯ��ƺ   (huashan)    /d/huashan/shaluo
��ɽ������   (henshan)    /d/henshan/lingxingmen
��ɽ����Ͽ   (hengshan)   /d/hengshan/jinlongxia
����ɽ����   (zhongnan)   /d/quanzhen/shanjiao
����ɽ����   (zhongtiao)  /d/huashan/jzroad3
������ɽ��   (mingjiao)   /d/mingjiao/shanmen
ѩɽ��ɽ��   (xueshansi)  /d/xueshan/shanmen
��ɽɽ·     (xiyu)       /d/xingxiu/tianroad2
����ɽ��     (wuliang)    /d/wuliang/shanlu6
̫������     (yanziwu)    /d/yanziwu/hupan
÷ׯ����     (meizhuang)  /d/meizhuang/gate
���Ʒ�ɽ���� (tiezhang)   /d/tiezhang/shanjiao
��ľ����ʯ�� (heimuya)    /d/heimuya/road1
*/
