// demote.c  display emote
#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit EMOTE_D;

int main(object me, string arg)
{
	string *e, msg, str;
	int i;

	e = sort_array(query_all_emote(), 1);
	msg = "\n";

	for(i=0; i<sizeof(e); i++)
	{
		if(emote[e[i]]["others_target"])
			str = emote[e[i]]["others_target"];
		else
		{
			if(emote[e[i]]["others"])
				str = emote[e[i]]["others"];
			else str = emote[e[i]]["others_self"];
		}
		if(!str) continue;
		str = replace_string(str, "$n", "ĳ��");
		str = replace_string(str, "$N", "��");
		str = replace_string(str, "$p", "��");
		str = replace_string(str, "$s", "׳ʿ");
		str = replace_string(str, "$r", "С���˵�");
		if( strlen(e[i]) > 6 )
			msg += e[i]+"\t : ";
		else
			msg += e[i]+"\t\t : ";
		msg += str;
	}

	msg += "\n";
	me->start_more(msg);

	return 1;
}

int help(object me)
{
	write(@HELP

ָ���ʽ : demote

    ���ָ������г�Ŀǰ����ʹ�õ�emote�ľ������ݡ�

HELP
	);

	return 1;
}

