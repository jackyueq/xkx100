// Feb. 6, 1999 by Winder
inherit ITEM;
void create()
{
        set_name( "����", ({ "wen shoupa"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���廨������\n");
             }
}
