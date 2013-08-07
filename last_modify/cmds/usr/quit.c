// /cmds/usr/quit.c
// Modified by Zeratul Jan 5 2001

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
	set("channel_id", "���߾���");
}

int main(object me, string arg)
{
	int i, t, e, p;
	string ct, ce, cp;
	object *inv, link_ob, ob;

	if( time() - me->query("last/lastquit") < 30 && !wizardp(me))
		return notify_fail("�����ϴ��뿪��Ϸ��ʱ�������㣬��ʱ�޷��뿪��Ϸ��\n");
	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");
	if( me->is_busy()) return notify_fail("��������æ���������£������˳���Ϸ��\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("���ϴ��Ķ���̫���ˣ��벻����Ϸ�ˡ�\n");

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				// Added by zeratul 2001-1-1
				if ( stringp( inv[i]->query( "money_id" ) ) )
					destruct( inv[i] );
				else
					DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

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
		if(wizardp(me) && me->query("env/invisibility") )
		{}
		else
		{
			link_ob->set("last_on", time());
			link_ob->set("last_from", query_ip_name(me));
			link_ob->save();
		}
		destruct(link_ob);
	}
	t=time()-me->query_temp("nowtime");
	e=me->query("combat_exp")-me->query_temp("nowexp");
	p=me->query("potential")-me->query_temp("nowpot");
	ct=chinese_number(t/3600)+"Сʱ"+chinese_number(t%3600/60)+"����"+chinese_number(t%60)+"��";
	ce=chinese_number(e);
	cp=chinese_number(p);
	log_file( "USAGE", sprintf("%s (%s) logout with %d second, %d exp, %d pot.\n", me->query("name"), me->query("id"), t, e, p));

	write("�㹲ͣ����"+ct+"������"+ce+"���飬��"+cp+"��Ǳ�ܡ�\n");
	write("��ӭ�´�������\n");

	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
	CHANNEL_D->do_channel(this_object(), "sys",
me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ�
��ͣ����"+ct+"������"+ce+"�㾭�飬��"+cp+"��Ǳ�ܡ������ "+reclaim_objects()+" ��������\n");
	me->set("last/lastquit", time());
	me->save();

//************* Added these for update topten ***********
        if( userp(me) )
                if( !wizardp(me) )
                {
                        ob=new("/clone/topten/magic-rice");
                        ob->movein(me);
                        ob->savetopten(me);
                        destruct( ob );
                }
//************* End of added ******************

	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit | exit

����(��)����ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}