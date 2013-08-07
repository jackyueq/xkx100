#include <ansi.h>
inherit F_CLEAN_UP;


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);

	if (! me->query("is_vendor"))
		return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");
	if (! present("shang ling", me))
		return notify_fail("��δ�������������ң�С��Ϊ�\n");

	if (me->is_fighting())
		return notify_fail("�㻹�Ǻúô���ļܰɡ�\n");

	if (me->query_temp("on_baitan"))
		return notify_fail("�������Ѿ�ռ��һ��̯λ�����ʿɶ�ֹ�ɡ�\n");
	if (me->is_busy() || me->query_temp("pending/deriving"))
		return notify_fail("��������æ���أ�û�����̯��㡣\n");
	if (me->query_condition("killer"))
		return notify_fail("�ٸ�������׷�����أ��ѵû��������̯��\n");
	if (where->query("no_trade"))
		return notify_fail("���ﳣ�йٱ�Ѳ�ߣ���û����ط������⡣\n");
	if (where->query("no_fight") && ! where->query("can_trade") && !wizardp(me))
		return notify_fail("�˴��������ӣ����ǻ����ط�������ɡ�\n");
	message_vision(WHT"$N"WHT"Ѱ�˿�յأ�һƨ����������������ͳ�һ�鲼̯���ڵء�\n" NOR, me);
	tell_object(me, HIC"��������԰���(" HIW "stock" HIC ")�����������(" HIW "unstock" HIC ")ĳ�ֻ��\n" NOR);

	me->set_temp("on_baitan", 1);
	me->set_temp("baitan_place",file_name(environment(me)));
	me->delete("vendor_goods");
//	me->set_short_desc("���ڵ��ϰ�̯��");
//	me->start_busy((:baitan:),(:halt_baitan:));
	me->set_temp("apply/short",({me->name()+"�����ڵ��ϰڵ�̯��"}));
	me->apply_condition("baitan",1);
//        me->start_call_out((:call_other,__FILE__,"baitan",me,3:), 10);
        return 1;
}

int baitan(object me)
{
//	switch (random(4))
	switch (random(15))
	{
		case 0:
			message_vision(CYN"$N"CYN"������һ�����ܣ�Ц���е��к������ˡ�\n"NOR, me);
			break;
		case 1:
			message_vision(CYN"$N"CYN"ߺ�ȵ����߹�·����Ҫ�������ҿ�����������\n"NOR, me);
			break;
		case 2:
			message_vision(CYN"$N"CYN"ߺ�ȵ�������������������������ȫ���������⡣\n"NOR, me);
			break;
		case 3:
			message_vision(CYN"$N"CYN"ߺ�ȵ���������������������Ʒ���۳��ۣ�������\n"NOR, me);
			break;
		default:
		  break;
	}

	return 1;
}

varargs int halt_baitan(object me,int silent)
{
	if (!silent)
	message_vision(WHT"$N"WHT"����̯�����ĸ��ǣ��ѻ���һ���Ե�����������վ��������\n" NOR, me);

	me->delete_temp("on_baitan");
	me->delete_temp("apply/short");
	me->delete_temp("baitan_place");
	me->delete("vendor_goods");
	me->set_short_desc(0);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : baitan

��̯��㣬���ۻ��

HELP);
	return 1;
}
