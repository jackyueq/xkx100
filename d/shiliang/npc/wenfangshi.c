// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�·�ʩ", ({ "wen fangshi", "wen" }) );
	set("gender", "����");
        set("title", "�¼�����");
	set("age", 45);
	set("long",
		"��λ�����¼����ģ��·�ʩ��\n");
	set("combat_exp", 1000000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 30);
	set("con", 25);
	set("int", 20);
	set("dex", 30);
	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);
        set("chat_chance", 15);
	set("inquiry", ([
		"�����ɾ�" : "��ѩ���������������һ��Ҫ������ʬ��ϣ�" ,
		"����"   : "���СѾͷ����а�ˣ����ҹ�����������Ҳ��Ϊ���ð���",
	]) );
	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_skill("sword", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
