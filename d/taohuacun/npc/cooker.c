// cooker.c
inherit NPC;
void  create()
{
	set_name("��ʦ��", ({ "da shifu" }));
	set("gender", "����");
	set("age", 50);
	set("per", 15);
	set("long", "һλԶ�������Ĵ�ʦ�������°˴��ϵ����������ʣ�µġ�\n");
	set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

