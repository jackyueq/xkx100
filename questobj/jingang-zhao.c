// jingang-zhao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"���"HIB"��"NOR, ({ "jingang zhao", "zhao" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ�����\n�ޱȵ��������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף�\n���Ƿ�����Ͻ�ħ������\n");
		set("material", "cloth");
		set("unit", "��");
		set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�\n˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
		set("remove_msg", HIY "$N������ִ����������������۵���СС��һ�š�\n" NOR);
		set("armor_prop/armor",100);
	}
	setup();
}
