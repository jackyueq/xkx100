//Edited by fandog, 02/15/2000

inherit NPC;

void create()
{
	set_name("�Һ�",({ "tao hong", "hong" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("long", 
"һλ����Ů�ˣ�ȴ���Ǹ�ؤ��������ͷ���棬��ɫ�㲣��½��������ۻ����塣\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"�Һ촹�������Ҳ��֪����үΪʲô��Ȼ��ϲ�����ˡ�\n",
		"�Һ�Ĩ��Ĩ���ᣬ��Ȼ�����Ǹ������С����Ǹ��յҵ��£��ֲ����Ҳ��á�\n",
		"�Һ��૵�����ү���ϼ���Ҫ��ǽ����ô�ֵ��ң��֡����ֲ�����Ϲ˵��\n",
	}) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

