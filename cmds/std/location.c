// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *place_desc = ({
	"���ݳǵ�����",
	"���ݳǵĸ�������",
	"���ݳǵ������",
	"���ݳǵķ�ѩ��",
	"���ݳǵ���ݴ���",
	"���ݳǵ��ػ���Ԣ",
	"�����ǵĿ͵�",
	"�ɶ��ǵĽ�����",
	"���ݳǵĿ͵�",
	"���ݳǵ�������",
	"���ݳǵ��ų���",
	"���ݳǵ�˳���ջ",
	"Ȫ�ݳǵĺ踣¥",
	"����ǵĿ͵�",
	"�����ǵ�������ջ",
	"����ǵ��紨��ջ",
	"�����ǵ�������ջ",
	"�����ǵĿ͵�",
	"�����ǵ�ĵ��¥",
	"���ݵ�ʮ�ﳤ��",
	"���ݵ���ʯ���",
	"���ݵ��յ�",
	"�����µ�������",
	"�䵱ɽ���ּ�С��",
	"����ɽ�ľ�ʮ�ŵ���",
	"����ɽ������ɽ·",
	"�����Ĵ����",
	"����Ĺٵ�"
});
int main(object me, string arg)
{
	object ob, where,tbg;
	mapping fam,fam2;
	int sp, dp, i, cost, count_lvl, bibo_lvl, placeno;
	string *dir, *place;

	seteuid(getuid());

	if( (!(fam = me->query("family")) || fam["family_name"] != "�һ���") )
		return notify_fail("ֻ���һ������ŵ��Ӳ���������˵����ڣ�\n");
	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	if( !present("tie bagua", me))
		return notify_fail("û�������ԣ�����û��������˵����ڣ�\n");

	tbg= present("tie bagua", me);
	if(tbg->query("ownmake")==1)
//	fam2 = me->query("weapon");
//	if(fam2["id"] == "tie bagua")
		return notify_fail("������������Բ��аɣ�\n");
	
	count_lvl = me->query_skill("count",1);
	bibo_lvl = me->query_skill("bibo-shengong",1);
	if( bibo_lvl < 30 && !wizardp(me))
		return notify_fail("���һ����书��δ���ţ��޷��������㣡\n");
	if( count_lvl < 30 && !wizardp(me))
		return notify_fail("�������������δ���죬�޷�������˵����ڣ�\n");
	if ( !arg ) return notify_fail("��Ҫ����˭�����ڣ�\n");
	if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ������˾��ڱ��ϣ��㲻����ë���ɣ�\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�����ڣ�\n");
	if (wizardp(ob) && !wizardp(me))
		return notify_fail("��Ҫ����˭�����ڣ�\n");
	if ( ob == me )
		return notify_fail("��û��ô���ɣ�Ҫ���˸������Լ������\n");
	cost = me->query("max_jing")/(1+me->query_skill("count",1)/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷�ȥ������˵����ڡ�\n");

	message_vision( CYN"$N����һֻ����������������Ĵָ�����������������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢��������λ��ϸ��������������\n\n\n"NOR, me);
	message_vision("���������дʣ���Ȼ��¶΢Ц: ���ˣ�\n\n",me);
	me->start_busy(3);

	sp = count_lvl*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;

	tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
	if ( random(sp) < random(dp)/2 )
		return notify_fail( "������Ȼ���£�ҡ��ҡͷ��˵�������Եģ�\n");

	me->receive_damage("jing", cost );
	where = environment(ob);
	if (!where) return notify_fail("����˲�֪��������Ү...\n");
	if (random(10) > 7)
	{
		printf("%s���ڿ�����%s��\n",
		(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
	dir = get_dir("/d/");
	if ( random(sp) < random(dp) || count_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
				return notify_fail(ob->name()+ "���ڿ�����"+to_chinese(dir[i])+"��ĳ���ط���\n");
		return notify_fail( ob->name()+"�����������أ���֪������\n");
	}
	if ( random(sp) < random(dp) || bibo_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
			{
				place = get_dir("/d/"+dir[i]+"/");
				placeno = random(sizeof(place));
				if(strsrch(place[placeno], ".c") >= 0)
				{
					if(!( where = find_object("/d/"+dir[i]+"/"+place[placeno])))
						where = load_object("/d/"+dir[i]+"/"+place[placeno]);
					return notify_fail(ob->name()+ "���ڿ�����"+to_chinese(dir[i])+"��"+where->query("short")+"��\n");
				}
				else return notify_fail(ob->name()+ "���ڿ�����"+to_chinese(dir[i])+"��ĳ���ط���\n");
			}
		return notify_fail( ob->name()+"�����������أ���֪������\n");
	}
	for (i=0; i<sizeof(dir); i++)
		if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
		{
			printf("%s���ڿ�����%s��%s��\n", ob->name(), to_chinese(dir[i]), where->query("short"));
			return 1;
		}
	return notify_fail("����˲�֪��������Ү...\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ: location <��ҵ� ID>

    ���ָ�����һ�������������֪���Ŀǰ���ڵ�λ�á�

HELP
	);
	return 1;
}

