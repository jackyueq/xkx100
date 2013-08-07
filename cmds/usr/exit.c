// /cmds/usr/quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
int savequit(object me);
void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
	set("channel_id", "���߾���");
}

int main(object me, string arg)
{
	if( time() - me->query("last/lastquit") < 30 && !wizardp(me))
		return notify_fail("�����ϴ��뿪��Ϸ��ʱ�������㣬��ʱ�޷��뿪��Ϸ��\n");
		
	if( environment(me)->query("no_quit"))
		return notify_fail("�ռ��Ѿ���գ�û�����ܹ��˳����ʱ����\n");

/*
	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");
*/
	if( me->is_busy()) return notify_fail("��������æ���������£������˳���Ϸ��\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("���ϴ��Ķ���̫���ˣ��벻����Ϸ�ˡ�\n");
	return savequit(me);
}
int savequit(object me)
{
	int i, t, e, p , pexp , ppot;
	int a=1;
	string ct, ce, cp;
	object *inv, link_ob, ob;
	string err;

        if( time()-me->query_temp("LAST_PKER_TIME")<7200&&!wizardp(me))
              return notify_fail("���ɱ�˲��ã���ʱ�޷��뿪��Ϸ��\n");

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");
	if(me->query_temp("guardto"))
		environment(me)->delete("guarded/"+me->query_temp("guardto"));

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
// ��ʦ�����˳�ʱ���� last_login
		if(!wizardp(me) || !me->query("env/invisibility") )
		{
		    a=0;
			link_ob->set("last_on", time());
			link_ob->set("last_from", query_ip_name(me));
			a=(link_ob->save());
		}
		destruct(link_ob);
	}
	t=time()-me->query_temp("nowtime");
	if (t<=0) t=1;
	e=me->query("combat_exp")-me->query_temp("nowexp");
	p=me->query("potential")-me->query_temp("nowpot");
	pexp = e*3600 / t;
	ppot = p*3600 / t;
	ct=chinese_number(t/3600)+"Сʱ"+chinese_number(t%3600/60)+"����"+chinese_number(t%60)+"��";
	ce=chinese_number(e);
	cp=chinese_number(p);
	log_file( "USAGE", sprintf("%-20s logout with %7d second, %6d exp, %6d pot, %6d exp/h %6d pot/h.\n", me->query("name")+"("+me->query("id")+")", t, e, p, pexp, ppot));
	if (e > 10000 || p > 5000 || e < -10000 || p < -5000)
		log_file( "NOTICE", sprintf("%-20s logout with %7d second, %6d exp, %6d pot. %6d exp/h %6d pot/h.\n", me->query("name")+"("+me->query("id")+")", t, e, p, pexp, ppot));

	write("�㹲ͣ����"+ct+"������"+ce+"���飬��"+cp+"��Ǳ�ܡ�\n");
	write("��ӭ�´�������\n");

	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
	CHANNEL_D->do_channel(this_object(), "sys", me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ�\n��ͣ����"+ct+"������"+ce+"�㾭�飬��"+cp+"��Ǳ�ܡ������ "+reclaim_objects()+" ��������\n");
	me->dismiss_team();
	me->set("last/lastquit", time());

//************* Added these for update topten ***********
	if( userp(me) )
		if( !wizardp(me) )
		{
			if (stringp(err= catch(ob=new("/clone/topten/magic-rice"))))
				message("channel:sys",me->name()+"topten����ʧ�ܣ���������ʦ������顣\n"+err,users());
			if (objectp(ob))
			{
				if (stringp(err = catch(ob->movein(me))))
				message("channel:sys",me->name()+"topten�ƶ�ʧ�ܣ���������ʦ������顣\n"+err,users());
				if (stringp(err = catch(ob->savetopten(me))))
				message("channel:sys",me->name()+"topten����ʧ�ܣ���������ʦ������顣\n"+err,users());
				destruct( ob );
			}
		}
//************* End of added ******************

    if ( a==1 &&	me->save() )
    {
    	destruct(me);
    	return 1;
    }
    else
    return notify_fail(HIR"���棺��������ʧ�ܣ��޷��˳���Ϸ����������ϵ��ʦ�����\n"NOR);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit | exit

    ��������ʱ�뿪�����Ϸʱ�������ô�һָ�
HELP
	);
	return 1;
}