// yuchang-jian.c �㳦��
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void setup()
{}

void init()
{
	if (!query("got"))
	add_action("do_jian", "jian");
}

void create()
{
	set_name(HIR"�㳦��"NOR, ({"yuchang jian", "jian", "sword"}) );
	set_weight(10000);

	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", "����Ǵ�˵�е��㳦����û�뵽����������֣�\n"
		"���̲�ס�������(jian)����������\n");
		set("material", "steel");
		set("no_get",1);
		set("no_drop",1);
		set("count",3);
    set("wield_msg", HIR "һ������Ѫ�⻮�����㳦��������$N" HIR "���С�\n" NOR);
    set("unwield_msg", HIR "��غ�����$N" HIR "���е��㳦������Ȼ��û ��\n" NOR);
	}
	init_sword(1);
	setup();
}

int do_jian(string arg)
{
	object me = this_player();
	if (!id(arg)) return 0;
	if (query("count") > 0 || me->query_dex()<40)
	{
	if (query("count")<=0) set("count",1);
	message_vision( HIR"$N����ؼ����㳦����ͻȻ�ӽ������"+chinese_number(query("count"))+"ö���룬����Ĵ���$N�����ڡ�\n"NOR, me);
  if (me->query_dex()>40);
	add("count",-1);
	me->unconcious();
	me->move("/d/tiezhang/shanlu6");		
	}
	else
	{
		message_vision( HIR"$N����ؼ����㳦����ͻȻ�ӽ������һö���롣����$N���з��������϶��˿�ȥ��\n"NOR, me);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"�õ�"+this_object()->query("name")+MAG+"����\n"NOR, users());
		tell_object(me,"�����һ��"+this_object()->query("name")+"��\n");
		set("long", "���Ǵ�������ŷұ����������ڱ���֮�㳦����\n���������࣬ϸ��֮��������Ѫ�⸡�֡�\n");
//		remove_action(me,"jian");
		set("got",1);
		set("weapon_prop/damage",300);
		set("rigidity",300/4);
		move(me);
		}
	return 1;
}

