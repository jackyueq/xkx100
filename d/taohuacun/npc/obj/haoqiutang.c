#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG "������" NOR, ({"haoqiutang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����̵������и�����ʮ������ӣ�ң���Ʈ���߰�Ƭ�ۺ�ɫ�Ļ��꣬
���³��������ӣ��������ɫ��ӳ�����޶�Ŀ��\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$Nȡ��ʮ��öӣ�ң�ȥ�ˣ��԰����Ƕ֮���������һ��ꡢ���Ͷ����
���ú�Ҷ���ɵ������У���΢������Ƭ�̡�\n\n");		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "������",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

