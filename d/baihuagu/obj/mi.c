// mi.c ��
inherit ITEM;
void create()
{
	set_name("����", ({"mi"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "һ�����ķ��ۣ�ɢ�������˵���ζ��\n");
		set("unit", "��");
		set("value",0);
		set("no_give", "�����������ǲ�Ҫ�����˵ĺá�\n");
		set("no_put",  "ѽ��С�����ˡ�\n"); 
	}
}
