inherit ITEM;

void create()
{
	set_name("����",({"seed","zhongzi"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
//                set("long", "һ��" + ob->query("name") + "��\n");
                set("unit", "��");
        }
}

