// er.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "�й�" NOR, ({ "pan guan","guan" }) );
	set("long", @LONG
������˾��ִ�ƹܴ��ڹ���ʩ����֮�٣��������ż�������������������
LONG);
	set("gender","����");
	set("str",1000);
	set("title",RED "����˾" NOR);			
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",10000);
	set("neili",10000);
	setup();
	carry_object( __DIR__"obj/shsbu" )->wear();
}
