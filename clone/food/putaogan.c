// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
void init();
void eat();

void create()
{
        set_name("���Ѹ�", ({"putao gan", "gan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���Ѹ��������߽����ز�������������ɿڣ�\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 4);
                set("food_supply", 10);
        }
}
void init()
{
        add_action("do_chi", "eat");
}


int do_chi(string arg)
{
        if( !this_object()->id(arg) ) 
     return 0;

        if( this_player()->is_busy() )
            return notify_fail("����һ��������û����ɡ�\n");

        if(!arg) 
     return notify_fail("��Ҫ��ʲô��\n");
           
        if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

        message_vision("$N�Ӷ����ͳ������Ѹɣ�һ��һ�ŵ��������\nһ�ţ�һ�ţ���һ�ţ�����\n" , this_player());
   this_player()->add("food", 30);
   destruct(this_object());
        return 1;
}

 
