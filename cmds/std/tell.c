// tell.c
#include <mudlib.h>
#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string name, refuse_name;
	mapping mud_list;
	string *clist=({});
	
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
/*
	if(me->query("channel/tell_block"))
		return notify_fail("���Ƶ�������ˣ�\n");
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("��ֻ����ʹ�ã�say����\n");
*/
//added by lion,�����ж������͵�MUD�������Լ�,�����Ѿ�����.

	if( sscanf(target, "%s@%s", target, mud)==2 ) 
	if(mud!=INTERMUD_NAME)
	{
		if( !find_object(DNS_MASTER) )
		return notify_fail("��·���鲢û�б����룬�������ⷢ��Ϣ��\n");
		mud_list = (mapping)DNS_MASTER->query_muds();
		if(!mud_list)
			return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");		
		mud = htonn(mud);
		if(!mapp( mud_list[mud] )) 
			return notify_fail(MUD_NAME + "��û�к�"+mud+"ȡ����ϵ������mudlist����鿴��\n");
    if (mud != mud_nname())      
//�ж����,��ʼ��mud������.		
		{
			GTELL->send_gtell(mud, target, me, msg);
		  write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		 return 1;
    }
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj))
		return notify_fail("û�������....��\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if (stringp(obj->query("env/can_tell")))
	clist = explode(obj->query("env/can_tell"),",");
	if( !wizardp(me) && (refuse_name == "all" || refuse_name == name)
	 && (!arrayp(clist) || member_array(name,clist)==-1))
		return notify_fail(obj->query("name")+"��������ߴߴ���ᡣ\n");
	write(HIG "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
	if (stringp(obj->query("env/auto_reply")) && query_idle(obj) > 60)
	tell_object(me,HIW"(�Զ��ظ�)"NOR+obj->name()+"�ش��㣺"+obj->query("env/auto_reply")+"\n");
	message("channel:snp", HIB"��������"+me->query("name")+"����"+obj->query("name")+"��"+msg+"\n"NOR, users());

	obj->set_temp("reply", me->query("id"));
	return 1;
}

//changed by lion@xjtufy3
string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) )
	{
		if(wizardp(ob) && ob->query("env/invisibility"))
			return "�����Ҳ�������ˡ�"; //respond no such user.
		if( ob->query("env/no_tell") ) return
			ob->query("name")+"���ڲ�������ߴߴ���ᡣ";
		if(!living(ob) || ob->query_temp("noliving") ||
			ob->query_temp("netdead")) 
			return ob->query("name")+"������������˵�Ļ���\n";
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR, cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR, capitalize(from), mud, msg ));
		ob->set_temp("reply", lower_case(from) + "@" + mud);
		return ob->query("name")+"�յ��������Ϣ��";
// if succeed, return target's name.
	} else return "�����Ҳ�������ˡ�";
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

    ����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}

