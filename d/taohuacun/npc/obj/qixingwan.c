#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW "������" NOR, ({"qixingwan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������������羵������Ư�����������ϣ�������Ƕ�����˳�Ϊ�������衱��\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N�������õ�������࣬��ú����ˮ�������ȣ��ټ��μ�����������������
$N��������ȥƤȥ�ͬϺ�ʻ��һ�𣬶��ϸĩ������ �����͡�Ȼ����
���ֽ��������Ĵָ��ʳָ֮���󼷳�һֻֻ��С���ӣ������� ���ü��ٵ�
����Ϻ��ĩ�������������һֻֻ�߹��߷�����ˮ�������졣Ȼ�����þ��ɹ���
�����弦�����ٴ���ˮ���н������̳����� �����������տ�������������Ҩ��
���룬�����۲�ĩ�������ۣ��������͡�\n\n"
		);		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "��������",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

