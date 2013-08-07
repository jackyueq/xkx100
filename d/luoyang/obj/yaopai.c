// yaopai.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name("����", ({ "yao pai", "yaopai" }));
	set("long", "����һ��������ơ�\n"+
"    ƾ�����ƣ���������(tisheng) �ͽ���(jiangchu)�����������
�������ڣ�������������(quzhu) ����ᡣ����������ʧһ������
����������Ա����ʮ��ʧ�������������˳�(tuichu)������ᣬ��
��һ���Ĵ���������
     ��(�š���)���޷��˻ᡣ��������λ(rangwei) ��������ڣ�
�������ˡ�����Υ�����ѵ�������������ʱ�ɳ���������õ�ִ����
��ǰ���ʹ�(chengchu)��
    ���������һλ�Ǳ������Ա��Ϊ����һ�����ڣ���������Ϊ��
ʾ�ҳ�֮���ģ������ȸ�һ���Դ�������Ϊ����Ͷ��״��
    ��������˵Ⱦ��ܻ��һ�����ƣ������Լ���Ȩ��ƾ������ʹ��
��Ȩ����
      ��(���)��    ���� ���� �ʹ� ���� ���� ���� ��λ
      ����(���)��  ���� ���� �ʹ� ���� �˳�
      ����            ���� ���� �ʹ� �˳�
      ����            ���� ���� �˳�
      ����            �˳�
      һ������        �˳�
���е������ġ���ײ��˵ȿ�������(renming)ר�����紫�����ϡ�
�������������������ȵȡ��κ��˵Ⱦ�����party������ı������
����
    ������Ҷ�ʧ�����ƣ����Ե����ֶ��Źط������Ϳ�ͷ(ketou)��
�ú�˼����
\n");
	set("weight", 300);
	set("no_get", 1);
	set("no_get_from", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("material", "��");
	}
	setup();
	init_dagger(5);
}

void init()
{
	add_action("do_tisheng","tisheng");
	add_action("do_jiangchu","jiangchu");
	add_action("do_renming","renming");
	add_action("do_quzhu","quzhu");
	add_action("do_tuichu","tuichu");
	add_action("do_chengchu","chengchu");
	add_action("do_rangwei","rangwei");
}

int do_tisheng(string arg)
{
	object where, ob, pai, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("��Ҫ����˭��ְ˾��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	where = environment(me);
	if ((string)where->query("short")!="����")
		return notify_fail("ֻ���ڹص����в�������ְ˾��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if(ob == me) return notify_fail("���Ǵ����ķ�����\n");
	if(!userp(ob))
		return notify_fail("��ֻ��������ҡ�\n");
	partynm = me->query("party/party_name");
	i = strlen(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("����Ȩ�����κ��ˡ�\n");
	if(!ob->query("party"))
	{
		if(me->query_temp("party/toumingzhuang") != ob->query("id"))
			return notify_fail("�Է�Ҫ�ȸ������ͷ��Ͷ��״��Ȼ������ܽ����˼ҡ�\n");
		ob->set("party/party_name", partynm);
		ob->set("party/rank", "һ������");
		ob->set("party/player", 1);
		ob->set("party/level", 6);
		ob->set("party/enter_time", time());
		pai=new(__DIR__"yaopai");
		pai->move(ob);
		message_vision("$N���һ�����ƣ�\n", ob);
		message("channel:chat", HIR"��ͨ�桿"+ob->query("name")+"��"+NATURE_D->game_time()+"��"HIG+me->query("party/rank")+me->query("name")+HIR"����������"+partynm+"��\n"NOR,users());
		return 1;
	}

	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"��ְ˾������ͣ���æ����ɶ��ѽ��\n");
	if(oblvl - mylvl == 1)
		return notify_fail("ֻ�������Է���Ϊ���������\n");

	ob->set("party/level", oblvl - 1);
	switch (oblvl)
	{
		case 3: ob->set("party/rank", "��"+partynm[i-2..i]+"��"); break;
		case 4: ob->set("party/rank", "����"); break;
		case 5: ob->set("party/rank", "����"); break;
		case 6: ob->set("party/rank", "����"); break;
	}
	message_vision("$N���Źص�������ȥ������������������ͷ��\n", ob);
	message("channel:chat", HIR"��ͨ�桿"HIY+ob->query("name")+"��"+NATURE_D->game_time()+"��"HIG+me->query("party/rank")+me->query("name")+HIY"����Ϊ"+partynm+ob->query("party/rank")+"��\n"NOR, users());
	return 1;
}

int do_jiangchu(string arg)
{
	object ob, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("��Ҫ����˭��ְ˾��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if(ob == me) return notify_fail("���Ǵ����ķ�����\n");

	partynm = me->query("party/party_name");
	i = strlen(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("����Ȩ�����κ��ˡ�\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"����û����ʲô���Ү��\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	oblvl = ob->query("party/level");
	if(oblvl == 6)
		return notify_fail(ob->query("name")+"��ְ˾�Ѿ�û�����ˣ���ͷ�ֻ�������ȥ�ˣ�\n");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"��ְ˾������ͣ����뷸�ϣ�\n");
	ob->set("party/level", oblvl + 1);
	switch (oblvl)
	{
		case 2: ob->set("party/rank", "����"); break;
		case 3: ob->set("party/rank", "����"); break;
		case 4: ob->set("party/rank", "����"); break;
		case 5: ob->set("party/rank", "һ������"); break;
	}
	message("channel:chat", HIR"��ͨ�桿"HIY+ob->query("name")+"��"+NATURE_D->game_time()+"��"HIG+me->query("party/rank")+me->query("name")+HIY"����Ϊ"+partynm+ob->query("party/rank")+"��\n"NOR, users());
	return 1;
}

int do_renming(string arg)
{
	object where, ob, pai, me = this_player();
	string obname, rankname, partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("��Ҫ����˭��ְ˾��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	where = environment(me);
	if ((string)where->query("short")!="����")
		return notify_fail("ֻ���ڹص����в�������ְ˾��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if( sscanf(arg, "%s to %s", obname, rankname) !=2)
		return notify_fail("renming ˭ to ר��\n");
	if(!objectp(ob = present(obname, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if(ob == me) return notify_fail("���Ǵ����ķ�����\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("ֻ����������������ר����\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"û�м����κΰ�ᣬ��������ɶ���ģ�\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	i = strlen(rankname);
	if( (strlen(rankname) < 4) || (strlen(rankname) > 6 ) )
	{
		return notify_fail("�Բ����������Ʊ����������������֡�\n");
	}
	while(i--)
	{
		if( rankname[i]<=' ' )
		{
			return notify_fail("�������Ʋ����ÿ�����Ԫ��\n");
		}
		if( i%2==0 && !is_chinese(rankname[i..<0]) )
		{
			return notify_fail("�������Ʊ����ǡ����ġ���\n");
		}
	}

	oblvl = ob->query("party/level");
	switch (oblvl)
	{
		case 3: ob->set("party/rank", rankname+"����"); break;
		case 4: ob->set("party/rank", rankname+"����"); break;
		case 5: ob->set("party/rank", rankname+"����"); break;
		default: return notify_fail(ob->query("name")+"��ְ˾��������ר����\n");
	}
	message_vision("$N���Źص�������ȥ������������������ͷ��\n", ob);
	message("channel:chat", HIR"��ͨ�桿"HIY+ob->query("name")+"��"+NATURE_D->game_time()+"��"+me->query("name")+"����Ϊ"+partynm+ob->query("party/rank")+"��\n"NOR, users());
	return 1;
}

int do_quzhu(string arg)
{
	object *inv, pai, ob, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!arg) return notify_fail("��Ҫ����˭��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if(ob == me) return notify_fail("���Ǵ����ķ�����\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 2)
		return notify_fail("��û��Ȩ��������ˡ�\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"û�м����κΰ�ᣬ�������ɶ���ģ�\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"��ְ˾������ͣ�������\n");
	ob->delete("party");
	inv = all_inventory(ob);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
//	ob->set("combat_exp", ob->query("combat_exp")*99/100);
	if ((int) ob->query("balance")>0 )
	   ob->set("balance",ob->query("balance")*99/100);
	ob->set("score", ob->query("score")*99/100);	   
	message_vision("$N��$n�����ջ�һ�����ƣ�\n", me, ob);
	message("channel:chat", HIR"��ͨ�桿"HIY+ob->query("name")+"��"+NATURE_D->game_time()+"��"HIG+me->query("party/rank")+me->query("name")+HIY"�����"+partynm+"���Ժ������Ϊ����"+partynm+"���棡\n"NOR, users());
	return 1;
}

int do_tuichu()
{
	object *inv, pai, me = this_player();
	string partynm;
	int i, j, mylvl;

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if(!me->query("party"))
		return notify_fail("��û�м����κΰ�ᣬ���㻹�������˰ɣ�\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl == 1)
		return notify_fail(partynm+"�����ִ�������ô���˳��أ�\n");
	me->delete("party");
//	me->set("combat_exp", me->query("combat_exp")*98/100);
	if ((int) me->query("balance")>0 )
	   me->set("balance",me->query("balance")*98/100);
	me->set("score", (int)me->query("score")*98/100);
	message_vision("$Nȡ�����ƣ��ݺ������ڵ��ϣ���ʾ���ѣ�\n", me);
	message("channel:chat", HIR"��ͨ�桿"HIY+me->query("name")+"��"+RANK_D->query_self_rude(me)+"����"+NATURE_D->game_time()+"��Ը�˳�"+partynm+"���Ժ�"+partynm+"һ����Ϊ����"+RANK_D->query_self_rude(me)+"һ�����棡\n"NOR, users());
	destruct(this_object());
	return 1;
}

int do_chengchu(string arg)
{
	object where, killer, ob, me = this_player();
	string partynm;
	int mylvl, oblvl, obskill;

	if(!arg) return notify_fail("��Ҫ�ʹ�˭��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(me->query("party/chengchu") + 3600 > time())
		return notify_fail(partynm+"ִ�����Ӳ������ã��޷��ɳ���\n");
	if(mylvl > 3)
		return notify_fail("��û��Ȩ���ʹ����ˡ�\n");
	ob = find_player(arg);
	if(!ob) return notify_fail("��Ҫ�ʹ����˲��ڽ����С�\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"û�м����κΰ�ᣬ��ʹ���ɶ���ģ�\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	oblvl = ob->query("party/level");
	obskill = ob->query_skill("parry",1);
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"��ְ˾������ͣ�������˼���ɲ��ɰ���\n");
	where = environment(ob);

	killer = new("/d/luoyang/npc/zhifa");
	killer->set("target", ob->query("id"));
	killer->set("owner", me->query("name"));
	killer->set("party/party_name", partynm);
	killer->set("party/rank", HIC"����"NOR);
	killer->set("combat_exp", ob->query("combat_exp") * 3 / 2);
	killer->set_skill("unarmed", obskill);
	killer->set_skill("parry", obskill);
	killer->set_skill("sword", obskill);
	killer->set_skill("dodge", obskill);
	killer->set_skill("force", obskill);
	killer->set_skill("taiji-shengong", obskill);
	killer->set_skill("taiji-quan", obskill);
	killer->set_skill("taiji-jian", obskill);
	killer->set_skill("liangyi-jian", obskill);
	killer->set_skill("tiyunzong", obskill);
	killer->map_skill("force", "taiji-shengong");
	killer->map_skill("unarmed", "taiji-quan");
	killer->map_skill("parry", "taiji-jian");
	killer->map_skill("sword", "liangyi-jian");
	killer->map_skill("dodge", "tiyunzong");
	killer->move(where);

	me->set("party/chengchu", time());
        tell_room(where, killer->query("name")+"���˹�����\n", ({killer}));
	return notify_fail("�Ѿ��ɳ�ִ������ǰ��"+ob->query("name")+"����֮���ˣ�\n");
}
int do_rangwei(string arg)
{
	object *inv, pai, ob, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!arg) return notify_fail("��Ҫ��λ��˭��\n");
	if(!me->query("party"))
		return notify_fail("�㲻�����κΰ�ᣡ\n");
	if(!me->query("party/player"))
		return notify_fail("��Ҵ����İ�����ʹ�����ƣ�\n");
	if(me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if(ob == me) return notify_fail("���Ǵ����ķ�����\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("�����ְ����ʲôλ�����԰���\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"û�м����κΰ�ᣬ���ò���λ����\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"�����Ǳ�İ���Ү��\n");
	if(ob->query("age") < 50 || ob->query("combat_exp") < 5000000)
		return notify_fail(ob->query("name")+"�����۵úܣ����㵣�˴��Σ�\n");
	ob->set("party/level", 1);
	ob->set("party/rank", me->query("party/rank"));
	message_vision("$N��$n����һ�����ƣ�\n", me, ob);
	message("channel:chat", HIR"��ͨ�桿"HIY+me->query("name")+"��"+RANK_D->query_self(me)+"��"+NATURE_D->game_time()+"��"HIG+partynm+me->query("party/rank")+HIY"֮λ����"+ob->query("name")+"������λ����ͬ��������"HIR"��ϲ��"+me->query("party/rank")+"��\n"NOR, users());
	me->delete("party");
	inv = all_inventory(me);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
	return 1;
}
 
string query_autoload()
{
	return 1 + "";
}
void owner_is_killed()
{
	destruct(this_object());
}

