#include <ansi.h>

inherit ITEM;

void create()
{
         switch(random(7)) {
        case 0 : set_name("ţ����Ĺ����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 1 : set_name("������Ż���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 2 : set_name("���Ի���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 3 : set_name("��ͷ��ս����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 4 : set_name("���޻���ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 5 : set_name("����ɱ��ʿ����ʯ", ({ "xiang shi", "shi", "stone"})); break;
        case 6 : set_name("���仭��ʯ", ({ "xiang shi", "shi", "stone"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 1000);
		set("long", "���Ƕ���ʯ�����е�һ��������������ɽ��������һ����\n");
		set("material", "stone");
		}
	setup();
}