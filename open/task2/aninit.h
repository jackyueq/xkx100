// aninit.h ����ɱ�ּ�飬�Լ���ʧ��ʱ��
#include <ansi.h>
#define A_TIME 20

string * shot_msg = ({
	"��أ��ֱ���һ�������������۵�$NͻȻ���˳�����\n",
	"���Ǹ��������ڣ�һ��$NЦ��������$nӭ���������ƺ�Ҫ����$nʲô������\n",
	"�ֽ���һ��$N�����������������ɹ��̫����ͻȻ������֮����Ծ��������\n",
	"һ��$Nվ�ڽ�������ߺ����ʲô����Ȼת�ۿ�����$n��ת����˹�����\n",
	"һ����ƽ����$Nվ���������ľȻ��ûʲô���顣\n",
	"������վ��һ��$N�����������ʲô�����������$n�ʹ��һ�����˹�����\n",
});

string * name_msg = ({
	"��å",
	"�����",
	"��ʿ",
	"����",
	"����",
	"�Ҷ�",
	"�ٱ�",
	"����",
	"��ؤ",
	"����",
	"��������",
	"�ϴ���",
	"������",
	"����",
	"С��",
	"����",
	"����",
	"�η�����",
	"��������",
});

string * long_id = ({
	"liu mang",
	"jinxiang ke",
	"dao shi",
	"xing zhe",
	"tiao fu",
	"jia ding",
	"guan bing",
	"xing ren",
	"qi gai",
	"bai xing",
	"flower girl",
	"lao chuanfu",
	"tangzi shou",
	"tie jiang",
	"xiao fan",
	"dao ke",
	"jian ke",
	"seng ren",
	"jianghu haoke",
});

string * short_id = ({
	"lm",
	"jk",
	"ds",
	"xz",
	"tf",
	"jd",
	"gb",
	"xr",
	"qg",
	"bx",
	"fg",
	"lc",
	"ts",
	"tj",
	"xf",
	"dk",
	"jk",
	"sr",
	"jh",
});

string * weapon_msg = ({
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/anqi",
	__DIR__"obj/chuidutong",
	__DIR__"obj/sheerkou",
});

void init()
{
	remove_call_out("do_check");
	call_out("do_check", 0);
	remove_call_out("do_wait");
	call_out("do_wait",A_TIME);
}

void do_check()
{
	object me = this_object();
	object ob;

	if (! living(me) || me->fighting() )
	{
		remove_call_out("do_check");
		call_out("do_check",0);
	}
	else
	{
		if( !ob = present("ren zhi",environment(me)) || ! living(me) || me->is_fighting())
		{
			remove_call_out("do_check");
			call_out("do_check",0);
		}
		else
		{
			message_vision(HIG+shot_msg[random(sizeof(shot_msg))]+NOR,me,ob);
			command("shot "+ob->query("id"));
			ob -> add("combat_num",1);
			message_vision(HIW"\n���㶨�����������Ǹ�$N��ȴ�Ѿ���ʧ����Ӱ�����ˡ�\n"NOR,me);
			destruct(me);
		}
	}
}

void do_wait()
{
	object ob;
	object me = this_object();

	if (me->is_fighting() || !living(me) )
	{
		remove_call_out("do_wait");
		call_out("do_wait",A_TIME);
	}
	else
	{
		message_vision("$N���������˵���������Ǹ��˲������ˣ��һ��ǻ�ȥ�ɡ�\n$N��û��Ϣ����Զ�����˿�ȥ��\n",this_object());
		destruct(me);
	}
}

