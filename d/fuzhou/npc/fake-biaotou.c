// fake-biaotou.c
#include <ansi.h>;
inherit NPC;
#include "finit.h"

void create()
{
	string weapon;
	int i;

	set_name("İ����ͷ", ({ "fake biaotou" }) );
	set("title", HIR"��"HIC"��"YEL"�ھ�"HIY"��ͷ"NOR);
	set("gender", random(2)>0 ? "Ů��" : "����" );
	set("age", 30 + random(20) );
	set("long","һ����ͨ���ˣ�������Ⱥ��û��һ��ͻ��֮����\n");

	weapon = weapon_msg[random(sizeof(weapon_msg))];
        set("combat_exp",100000 +random(50000));
        set("max_qi",1200+random(300));
        set("max_jing",400+random(200));
        set("str", 20 + random(11));    // ����
        set("per", 20 + random(11));    // ��ò
        set("int", 20 + random(11));    // ����
        set("con", 20 + random(11));    // ����
        set("dex", 100 + random(11));   // ��
        set("kar", 20 + random(11));    // ��Ե
        setup();
	carry_object(weapon);
	carry_object("/clone/misc/cloth")->wear();
}

