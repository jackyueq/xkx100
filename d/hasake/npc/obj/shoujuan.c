// bandage.c

#include <ansi.h>
inherit ITEM;
inherit F_EQUIP;
void create()
{
        set_name( HIW"�־�"NOR, ({ "shou juan", "piece"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", "����һ��ѩ�׵��־\n");               
                set("armor_type", "bandage");
                set("armor_prop/attack", -10);
                set("armor_prop/defense", -10);
                set("armor_prop/unarmed", -10);
        }
}

void init()
{
        add_action("do_bandage", "bandage");
        add_action("do_look", "look");
}

int wear() { return 0; }

int do_look(string arg)
{
        object me;
        me = this_player();
 
        if(!arg) return 0;
       
        if(id(arg)){
        if(query("blood_soaked") >= 2 && random(me->query("kar")) < 10 && !query("blooded"))
           {
            message_vision("$N���������־���ϸ�ض����š�\n", me);
            if(!query_temp("blooded")){            
                 tell_object(me, HIY "\n��ͻȻ���������־��е���֣���Ⱦ��Ѫ�ĵط����˵�仯��\n\n"NOR);
                 set_temp("blooded", 1);
                 return 1;
                 }
            else if(query_temp("blooded") < 3){
                 tell_object(me, HIY "\n�����־Ⱦ��Ѫ�ĵط���ʼ�����˵�仯��\n"NOR);
                 add_temp("blooded", 1);
                 return 1;
                 }
            else {                 
                 tell_object(me, HIY "\n����ϸ�о���һ�£��ŷ��������ŵ�ͼ����Ѫ���˺�������ֳ�ͼ������\n\n"NOR);
                 set("blooded", 1);
                 delete_temp("blooded");
                 if (query("owner")==me->query("id"))
                   me->set_temp("li_meet",2);
                 set("long", "����һ�ű�ѪȾ���˵��־�����ͼ����Щ��֣��������ŵ�ͼ��\n");
                 return 1;
                }
            }
        else {
             write(query("long"));
             return 1;
             }
      }
        
}

int do_bandage(string arg)
{
        object ob;
        if( (int)query("blood_soaked") >= 2 )
                return notify_fail( name() + "�Ѿ�����Ѫ��͸�����������ˡ�\n");

        if( query("equipped") )
                return notify_fail( name() + "�Ѿ���������˿����ˣ������Ҫ�����������ˣ������Ȱ�����������\n");

        if( !arg ) ob = this_player();
        else {
                ob = present(arg, environment(this_player()));
                if( !ob || !userp(ob))
                        return notify_fail("��Ҫ��˭���ˣ�\n");
        }

        if( this_player()->is_fighting()
        ||      ob->is_fighting() )
                return notify_fail("ս���в��ܹ��ˡ�\n");

        if( (int)ob->query("eff_qi") == (int)ob->query("max_qi") )
                return notify_fail( (ob==this_player()? "��" : ob->name())
                        + "��û���ܵ��κ����ˡ�\n");

        if( ob->query_temp("armor/bandage") )
                return notify_fail( ob->name() + "���ϵ����Ѿ��������������ˡ�\n");

        if( !move(ob) ) return 0;

        if( ob==this_player() )
                message_vision("$N��" + name() + "���Լ����ˡ�\n", this_player());
        else
                message_vision("$N��" + name() + "��$n���ˡ�\n", this_player(), ob);
        ::wear();
        ob->apply_condition("bandaged", 40);
        add("blood_soaked", 1);
        
        return 1;
}

void remove(string euid)
{
        ::remove(euid);
        if( query("equipped") && environment() )
                environment()->apply_condition("bandaged", 0);
}