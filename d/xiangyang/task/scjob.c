#include <ansi.h>
#include <dbase.h>
#include <login.h>
int ask_shoucheng()
{
	object *ene;
	object me,ob; 
	object* ob_list;
	int i;
	
	me = this_player();
	ob = this_object();

	if( ob->query("shoucheng_start") )
	{
		tell_object(me,"��������˵�������ղž�Ԯ��Ӣ����ȥ���ţ��㿴ȥ���æ��Σ���\n");
		return 1;
	}
	if(!me->query("family/family_name"))
	{
		tell_object(me,"��������Ц�������������ɣ���֪��ʦ��˭����\n");
		return 1;
	}
	if((int)me->query_temp("guosc_mis_flag") > 0 )
	{
		tell_object(me,"����˵�������㲻�������������𣿡�\n");
		return 1;
	}
	if ((int)me->query("combat_exp")<100000)
	{
		tell_object(me,"����Ц�����������޸���֮�������Ǳ��������Ϊ�ã���\n");
		return 1;
	}
	if ( (int)me->query_skill("force") < 50 )
	{
		tell_object(me,"����Ц�������س��Ǽ�Σ�չ������ҿ���Ļ����ڹ���Ϊ���㣬����ð�գ���\n");
		return 1;
	}
	if ((int)me->query_condition("guosc_mis")>1)
	{
		tell_object(me,"�����������һ������������ѽ������Σ�������������ְ�أ�������ĸ�λȥ����\n");
		return 1;
	}
	ob->set("shoucheng_start", 1);
	call_out("new_start_scjob",900,ob);
	call_out("guosc_begin",30,me);
	me->set_temp("guosc_mis_flag",1);
	me->set_temp("guosc_mis_num",1);

	ob_list = children("/d/xiangyang/task/wandao");
    for(i=0; i<sizeof(ob_list); i++) 
	{
			destruct(ob_list[i]);
    }
	switch( random(4) )
	{
		case 0:
			me->set_temp("guosc_mis_where","��������");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"�������㶣�������������ɹ������ַ���ԭ���������ȥ�������Ű����ξ��سǰɣ���\n");
			break;
		case 1:
			me->set_temp("guosc_mis_where","��������");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"�������㶣�������������ɹ������ַ���ԭ���������ȥ�������Ű����ξ��سǰɣ���\n");
			break;
		case 2:
			me->set_temp("guosc_mis_where","��ȸ����");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"�������㶣�������������ɹ������ַ���ԭ���������ȥ��ȸ���Ű����ξ��سǰɣ���\n");
			break;
		case 3:
			me->set_temp("guosc_mis_where","�׻�����");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"�������㶣�������������ɹ������ַ���ԭ���������ȥ�׻����Ű����ξ��سǰɣ���\n");
			break;
	}
	message("channel:sys", HIR"�����������ǡ�"+me->query("name")+"��������"+me->query_temp("guosc_mis_where")+"����\n"NOR, users());
	return 1;
}

int new_start_scjob()
{ 
   this_object()->delete("shoucheng_start", 1);
}

void guosc_begin(object me)
{
	object *target, robber;
	mapping my_fam = me->query("family");
	int i;
	target = users();
	if ( me->query_temp("guosc_mis_flag") == 1 && (int)me->query_condition("guosc_mis") )
	{
		me->remove_call_out("guosc_begin");
		call_out("guosc_begin",10,me);
		return;
	}
	else if ( me->query_temp("guosc_mis_flag") != 3&& (int)me->query_condition("guosc_mis"))
	{
		if ( environment(me)->query("short")!=me->query_temp("guosc_mis_where") )
		{
			me->remove_call_out("guosc_begin");
			call_out("guosc_begin",10,me);
			return;
		}
		else
		{
			for(i=0;i<sizeof(target);i++)
		{
			if(target[i]->query("family/family_name") == my_fam["family_name"] && target[i]->query("id")!=me->query("id"))
			message("vission",HIR"һֻ������Ѫ�ĸ��ӷɵ�����ǰ������һ��ֽ����\n"HIW"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U          �ɹ�����������ԭ��"+me->query_temp("guosc_mis_where")+"�Խ���          �U\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a \n                              "+NOR+CYN+me->query("family/family_name")+" "+me->query("name")+"("+me->query("id")+")\n" NOR,target[i]);
		}
			robber=new(__DIR__"robber1");
			robber->do_change(me);
			robber->move(environment(me));
			message_vision(HIR"ͻȻ����������һ���ɹű�ʿ��\n" NOR,me);
			robber->kill_ob(me);
			me->kill_ob(robber);
		}
	}
	else
	{
		me->remove_call_out("guosc_begin");
	}
}

int job_over(string arg)
{
	int job_pot,job_exp;
	object me = this_player();

	if(!arg) return 1;

	if(arg!="over") return 1;
	if(!me->query_temp("guosc_mis_flag"))
	{
		tell_object(me,"�����������һ�������������û������Ҳ����������\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")!=3)
	{
		tell_object(me,"�����������һ������������û��ɣ�Ҳ����������\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_num")<3)
	{
		tell_object(me,"�����������һ����������ɱ�˼������ˣ��㻹�����ͣ���\n");
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")==3)
	{
		tell_object(me,"������������ļ��˵������Ϊ��ɱ�У���������\n");
		job_exp=((int)me->query_temp("guosc_mis_num"))*150;
		job_pot=job_exp*1/3;
		job_exp=job_exp;
		if (job_exp>4000) 
			job_exp=4000+(job_exp-4000)/10;
		if (job_pot>1300) 
			job_pot=1300+(job_pot-1300)/2;
    if (job_pot>job_exp/2)
      job_pot=job_exp/2-500;
    log_file("mission/guo_shoucheng",sprintf("%-20s �س�ɱ��%3i���ɹű������%-5i ���� %-5i Ǳ��\n",me->query("name")+"("+me->query("id")+")",me->query_temp("guosc_mis_num"),job_exp,job_pot));
		me->add("combat_exp", job_exp);
		me->add("potential",job_pot);
	me->set_temp("prize_reason","�س�");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",job_exp);
	me->set_temp("prize_pot",job_pot);
		tell_object(me, HIW"�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��"+chinese_number(job_pot)+"��Ǳ�ܡ�\n"NOR);
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		this_object()->delete("shoucheng_start", 1);
		return 1;
	}
}
