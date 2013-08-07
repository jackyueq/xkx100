// npc.c

#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
	object ob;

	if( !objectp(ob = new(file)) ) return 0;
	ob->move(this_object());
	return ob;
}

object add_money(string type, int amount)
{
	object ob;

	ob = carry_object("/clone/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(amount);
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");

	if( is_fighting() )	switch(att) {
		case "heroism":
			command("say �ߣ����аɣ�\n");
			break;
		default:
			command("say ���ж�Ϊʤ���ⲻ������̫����\n");
			return 0;
	}

	if( (int)query("jing") * 100 / (int)query("max_jing") >= 70
	&&	(int)query("qi") * 100 / (int)query("max_qi") >= 70 ) {
		switch(att) {
			case "friendly":
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(who)
					+ "�Ķ��֣�\n");
				return 0;
			case "aggressive":
			case "killer":
				command("say �ߣ����аɣ�\n");
				break;
			default:
				if( !is_fighting() )
					command("say ��Ȼ" + RANK_D->query_respect(who)
						+ "�ͽ̣�" + RANK_D->query_self(this_object())
						+ "ֻ�÷��㡣\n");
		}
		return 1;
	} else
		return 0;
}
///////////add from here///////////
//2004.10.11  qingyun add 
//accept_hit accept_kill accept_touxi accept_ansuan 


int accept_hit(object who)
{
/*    

���ȡ�����ע�� ��ôhit���ܵ���kill
��Ϊľ��Ҫ����hit ����ȥľ�˾ʹ�����
        int t;
        string att;
        int perqi;
        int perjing;

        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "hit");

        att = query("attitude");
        perqi = (int)query("qi") * 100 / query("max_qi");
        perjing = (int)query("jing") * 100 / query("max_jing");

        add_temp("attempt_hit", 1);
        t = query_temp("attempt_hit");

        if (perqi >= 30 && perjing >= 30)
        {
                switch(att)
                {
                case "friendly":
                        command("say ��λ" + RANK_D->query_respect(who)
                                + "��������");
                        break;
                case "aggressive":
                        if (random(t) > 8)
                        {
                                command("say �����̵ģ���ô��ô��������" +
                                        RANK_D->query_self_rude(this_object()) +
                                        "����ɱ�䣡");
                                kill_ob(who);
                                return 1;
                        }
                        command("say �ø�" + RANK_D->query_rude(who) +
                                "�����У�");
                        break;
                case "killer":
                        if (random(t) > 2)
                        {
                                command("say �ߣ������ҵ��������ˣ�" +
                                        RANK_D->query_self_rude(this_object()) +
                                        "�������أ�");
                                kill_ob(who);
                                return 1;
                        }
                        command("say �ߣ����аɣ�");
                        break;
                default:
                        if (random(t) > 7)
                        {
                                command("say ����������");
                                kill_ob(who);
                                return 1;
                        }
                        command("say ��λ" + RANK_D->query_respect(who)
                                + "��������");
//                        break;
                        switch (random(3))
                        {
                        case 0:
                                command("say ��������");
                                break;
                        case 1:
                                command("say �Ǿͽ���������");
                                break;
                        case 2:
                                command("say ���ɣ��һ��������㲻�ɣ�");
                                break;
                        }
                        break;
                }
        } else
        {
                switch(att) {
                case "friendly":
                        command("say ��Ȼ" + RANK_D->query_respect(who)
                                + "���������ֻ�в������ˣ�");
                        break;
                case "aggressive":
                case "killer":
                        command("say " + RANK_D->query_rude(who) +
                                "����������");
                        break;
                default:
                        command("say �㲻�ʣ��Ҳ��壡" + RANK_D->query_rude(who) +
                                "���ɲ�Ҫ���ҡ�");
                        break;
                }
                this_object()->kill_ob(who);
        }
*/
        return 1;
}

int accept_kill(object who)
{
        if (! living(this_object()))
                return 1;

        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "kill");

/*        switch(query("attitude"))
        {
        case "friendly":
                command("say ��Ȼ" + RANK_D->query_respect(who)
                        + "��˱��ȣ�Ī�����²����飡");
                break;
        case "aggressive":
        case "killer":
                command("say " + RANK_D->query_rude(who) +
                        "������Ľ��죬������ļ��գ���");
                break;
        default:
                command("say �ã�" + RANK_D->query_rude(who)
                        + "�����Ǿ�һ��������");
                break;
        }
*/
        return 1;
}

int accept_ansuan(object who)
{
        if (! query("can_speak"))
        {
                kill_ob(who);
                return 1;
        }

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "ansuan");

        command(random(2) ? "say �ţ���ô��" : "say ��ѽ�����ã�");
        return 1;
}

int accept_touxi(object who)
{
        if (! query("can_speak"))
                return 1;

        if (this_object()->is_guarder())
                return this_object()->check_enemy(who, "touxi");

        command(random(2) ? "say �ţ���ô...��˭��" : "say ������.. ");
        return 1;
}
//////////add end///////////////////////

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	// Are we at home already?
	if( !environment()
	||	environment()==home )
		return 1;

	// Are we able to leave?
	if(!living(this_object()) || this_object()->query_temp("noliving") ||
		is_fighting() )
		return 0;
		
	// let me leave ,add by sir
	if( !mapp(environment()->query("exits")) && (int)this_object()->query_temp("let_me_leave")<=5 )
	{
		 this_object()->add_temp("let_me_leave",1);
		 return 0;
	}

	// Leave for home now.
	message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
		environment(), this_object());
	return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	string *msg;
	int chance, rnd;

	if( !environment() ) return 0;

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	mapping exits;
	string *dirs;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	string spell_skill;

	if( stringp(spell_skill = query_skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = query_skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
	object weapon;
	string martial_skill, act;

	if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
		return 0;
	martial_skill = query_skill_mapped(martial_skill);
	if( stringp(martial_skill) )
		return SKILL_D(martial_skill)->perform_action(this_object(), act);		
}

// Following add for making love...hehe ! Dec.1997 Venus
/*
int accept_ai(object who)
{
	int tage;

	tage = query("age");

	if (tage>17)
	{
		command("say ����" + RANK_D->query_respect(who)
	+ "���ۣ�" + RANK_D->query_self(this_object())	+ "�������������\n");
		return 1;
	} else
		return 0;
}
*/
