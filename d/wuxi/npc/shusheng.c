// shusheng.c

inherit NPC;

void create()
{
	set_name("��������", ({ "maihua shusheng", "shusheng" }) );
	set("gender", "����" );
	set("age", 32);
	set("int", 28);
	set("long", "һ�������ĵ���������ֻ�ܿ�һ�ֵ����ڷ羰�����������ֻ�Ϊ�������г�����һЩ���ε����顣\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

