// cow.c

inherit NPC;

void create()
{
        set_name("ˮţ", ({ "shui niu", "niu", "cow" }));
        set("long","һͷ�Ϸ�ɽ��������ˮţ���Ǹ�����������Ҳ���������������ˮ��ïʢ������ʮ�ַ�׳��\n");
	set("race", "����");
        set("age", 5);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}


void die()
{
	object ob, corpse;
	message_vision("$N�������һ�����������ڵ�����ȥ�ˡ�\n",this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/niuhuang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
