// Feb. 6, 1999 by Winder
inherit NPC;
void create()
{
	set_name("ũ��", ({ "nong fu","nong","fu"}) );
	set("gender", "����" );
	set("age", 24+random(10));
	set("long", "����һ��ɽ��ũ��ʮ�ִ��ס�\n");
	set("shen_type", 1);
	set("combat_exp", 4000);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
        set("chat_msg", ({
        "ũ������һ�ڣ�˵�����¼�û���ö��������Ů������̣��\n",
        "ũ��ҧ���гݵ�˵�����¼Һ��аԵ��������кñ���\n"
        }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
