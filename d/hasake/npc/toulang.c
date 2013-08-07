inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("ͷ��", ({ "toulang", "lang" }) );
	set("race", "Ұ��");
	set("age", 10);
        set("unique", 2);
        set("long", "����Ⱥ�ӣ���ֻ��ͷ�Ĵ���Ǳ������Ĵ�һ�����ϣ��ͳ��غ��š�\n");
        set("attitude", "aggressive");	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "ǰצ" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi", 450);
        set("max_jing", 200);
        set("eff_jingli", 200);
	set("combat_exp", 9500);
        set("chat_chance", 20);
	set("chat_msg", ({
                "ͷ�ǵ�˫Ŀ�ںڰ������ź�⣬������ע�������һ��һ����\n",
		(: random_move :),
                "ͷ�Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
	}) );
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 14);        
        set("senlin", 1);
	setup();
}

void die()
{
	object ob;
    message_vision("$N��ҵĺ��˼���, �ڵ��ϴ��˼��������������ˡ�\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
