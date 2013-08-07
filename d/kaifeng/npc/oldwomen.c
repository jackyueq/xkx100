#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������̫", ({"lao taitai", "lao", "taitai"}));
        set("gender", "Ů��");
 	set("long", "�����������̫̫��\n");
        set("combat_exp", 5000);
   	set("age",64);

	set_skill("dodge", 20);
   	set_skill("force", 20);
   	set_skill("parry", 20);
   	set_skill("unarmed", 20);
   	set_skill("sword", 20);

   	set("chat_chance", 20);
   	set("chat_msg",({
        	(:random_move:),
        }));

   	setup();
   	add_money("silver", 2);
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
  	object ob;
  	::init();
  	if (interactive(ob = this_player()) && ! is_fighting())
	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object xiang = present("xiang", environment());

        if (! ob || environment(ob) != environment())
                return;

 	if (xiang)
	{
  		message_vision(CYN "$N" CYN "��������$n" NOR +
                               CYN "�򵹣����������дʡ�\n" NOR,
                               this_object(), xiang);
    		return;
   	}
  	tell_object(ob, CYN "������̫�������������Ҫ������Ҫ��"
                        "�ع���" NOR);
  	return;
}
