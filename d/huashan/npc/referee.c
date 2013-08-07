
inherit NPC;
#include <ansi.h>;


int ask_me();

void create()
{
	set_name("��ƽ��", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");

	set("combat_exp",60000);
                set("shen_type", 1);
	set("attitude", "friendly");

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);
	set("owner","mud os");

	set("win_times", 0);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);
	set("inquiry", ([
		"��ɽ�۽�"       : (: ask_me :),
	]));
  
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"��ƽ�Ӷ���˵���������ڻ�ɽ�۽����ھ����أ������ʲô����\n");
		return 1;
	}
        else if (PK_D->is_ready())
        {
        	tell_object(me,"��ƽ�Ӷ���˵�������ܺã����ڻ�ɽ�۽���Ҫ��ʼ����Ҫ����(sign)ô����\n");
		return 1;
	}
	else
	{
        	tell_object(me,"��ƽ�Ӷ���˵��������ɽ�۽������������Űɡ�Ҫ�����ģ�����Ҫ�����ȥ����(join)Ҳ�С���\n");
		return 1;
	}
}

int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision(CYN "\n$N" CYN "����Ц����$n" CYN "�������ã����ã���Ҳ��ǩ������\n" NOR, me, this_object());
        
        if (stringp(msg = PK_D->reject_join(me)))
        {
		tell_object(me,"��ƽ�Ӷ���˵������"+msg+"��\n");
                return 1;
        }
        
	me->set_temp("bwdh_join",1);
       	tell_object(me,"��ƽ�Ӷ���˵��������ɽ�۽����Ͼ�Ҫ��ʼ�ˣ���������׼���͸Ͽ����ɣ�join������\n");
        return 1;
}

int do_join()
{
        object me;
        object *obs;
        int i;
        
        me=this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"��ƽ�Ӷ���˵���������ڻ�ɽ�۽����ڽ����У��㻹�ǵȵȰɡ���\n");
		return 1;
	}
	
	if (PK_D->is_ready() && !me->query_temp("bwdh_join") )
        {
        	tell_object(me,"��ƽ�Ӷ���˵��������Ҫ�μ��۽��ĸϽ��ȱ�����sign���ɣ������˻��ǵȵȰɡ���\n");
		return 1;
	}
	
	obs = all_inventory(me);
	for ( i = 0 ; i < sizeof(obs); i++)
        {
                if (obs[i]->is_character())
                {
                        tell_object(me,"��ƽ�Ӷ���˵�������������ϱ���˭�أ������ȷ��������ɣ���\n");
                        return 1;
                }
        }
        
        message_vision(CYN "$N" CYN "��Ц��$n" CYN "��������Ҫ�μӻ�ɽ�۽������пɺã�\n" NOR, this_player(), this_object());

        if (!PK_D->join_competition(this_player()))
        {
                message("vision", HIW + this_player()->name() + HIW "һ������������֡�\n" NOR, environment());
                return 1;
        }
        else
        {
        	tell_object(me,"��ƽ�Ӷ���˵���������»��Ǹ��������μӻ�ɽ�۽��ɣ���\n");
                return 1;
        }
        	      
}

void unconcious()
{
        die();
}


