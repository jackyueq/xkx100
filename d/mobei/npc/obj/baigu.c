// baigu.c
// Last Modified by winder on May. 25 2001

inherit ITEM;
void create()
{
	set_name("����ͷ��", ({ "kulou tougu" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�׹ǲҲң�ÿ��ͷ�ǵĶ��϶������ָ�ס�\n");
	}
}


