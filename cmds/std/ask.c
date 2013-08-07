// /cmds/std/ask.c

// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by Zeratul Jan 5 2001
// Modified by Constant Jan 12 2001

#include <ansi.h>
object i_have(object env,string name); // env��ȡ���� name����Ʒ
string filter_color(string arg);

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

//	if( !objectp(ob = present(dest, environment(me))) )
	if( !objectp(ob = i_have(environment(me),dest)) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") )
	{
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) || ob->query_temp("noliving") )
	{
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n", me, ob);
		return 1;
	}
	if (topic == "������ͽ" && ob->party_quest_betrayer(me))
		return 1;

	if (topic == "���ɼ�ϸ" && ob->party_quest_thief(me))
		return 1;

	if ((topic == "quest" || topic == "������ɱ" ) && ob->party_quest_kill(me))
		return 1;

	if ( topic == "ȡ��������ͽ����" && ob->cancle_quest_betrayer(me) )
		return 1;

	if (topic == "ȡ�����ɼ�ϸ����" && ob->cancle_quest_thief(me))
		return 1;
		
	if (topic == "cancel" && ob->cancle_quest_kill(me))
		return 1;
		
	if (topic == "�����ؼ�" && ob->party_quest_book(me))
		return 1;

	// ����������Ҫ����ʦ�Ĺ��ܡ�
	// Added by Constant Jan 12 2001
	if ( (topic == "��ʦ" || topic == "����") && ob->betray(me, 0))
		return 1;
		
	//�������ŵ���������Ҫ�������͵�
	if (topic == "���͵�" && ob->xkd(me))
		return 1;
		
		
	if (msg = ob->query("inquiry/" + topic)) {
		if (stringp(msg)) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
	{
			if (ob->accept_ask(me,topic))
			 return 1;
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
  }
	return 1;
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

    ���ָ���ڽ���ʱ����Ҫ��ͨ��������ɴ�һָ����ܻ�ý�һ������Ϣ��
�У���塢����塢���������Ԥ��Ĺؼ��ʡ����мǣ����ݳ�����
�߽�ӹ�����й���ڶ���ΣУ�ѯ����Ӧ���������ƽ����ѣգţӣԵĹؼ���
�����ڣ���壬����壬���������⼸��Ԥ��ֵ���ΣУö������ڻ�
��ġ���

HELP
   );
   return 1;
}

