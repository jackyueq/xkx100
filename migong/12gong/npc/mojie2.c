inherit NPC;
#include "star.h"
 
void create()
{
        set_name("����ŵ˹", ({"kelowooz two", "kelowooz two"}));
        set("long", "��˵�е�����֮���ػ���Ħ����.\n");
        set("gender","����");
        set("title", "������֮��");
        set("attitude", "friendly");
        set("no_get",1);
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "����ŵ˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("renma", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force",4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 22000);
        set("max_gin", 22000);
        set("max_jing", 22000);

        setup();
        carry_object(__DIR__"obj/mj_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}

void init()
{
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N��Цһ��������$N������ˣʲô������\n",me);
        return 1;
} 

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		HIY + name() + "˵�����������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
		+ name() + "��Ϊһ����⣬��ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
