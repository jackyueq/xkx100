
inherit ITEM;

void create()
{
	set_name("�ײ���",({"baicai seed"}));
	set_weight(50);
	set("value", 100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ײ��硣\n");
                set("unit", "��");
        }
}

