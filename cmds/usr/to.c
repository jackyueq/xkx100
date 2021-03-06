// /cmds/usr/to.c

// Modified by Constant Jan 4 2001

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

// 增加下面这个数组，限制某些指令不能以to来引用。
// Added by Constant Jan 4 2001
string *cannot_to = ({
	"nick",
	"set",
	"unset"
});

int main(object me, string arg)
{
	if (!wizardp(me) && member_array(arg, cannot_to) != -1) 
		return 0;
	me->edit( (: this_object(), ({ "do_to", me, arg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
指令格式 : to <指令>

    可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
    如to chat即可一次送出多行文本，to tell <某人> 则一次把多
行文本告诉给某人。

HELP
	);
	return 1;
}

