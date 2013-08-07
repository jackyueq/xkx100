// /cmds/usr/describe.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;
	
	if( !arg ) return notify_fail("指令格式：describe <描述>\n");
	if( arg == "none" ) 
	{
		me->delete("long");
		write("你取消了对自己的描述。\n");
		return 1;
	}
	if( !wizardp(me) && (int)strlen(arg) > 40 )
	{
		txt = explode(arg,"\n");
		if( sizeof(txt) > 8 )
			return notify_fail("请将您对自己的描述控制在八行以内。\n");
		arg = implode(txt, "\n") + "\n";
	}

	me->set("long", arg);
	write("描述设定完毕。\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：describe <描述 | none>

     这个指令让你设定当别人用 look 指令看你时，对你的描述，通
常当你的描述超过一行时可以用 to describe 的方式来输入。

TEXT
	);
	return 1;
}
