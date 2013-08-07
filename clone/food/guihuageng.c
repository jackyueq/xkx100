// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// guihuageng.c ��ѩ����

inherit ITEM;

void init();
void eat();

void create()
{
   set_name("��ѩ����",({"guihua geng", "guihua", "geng"}));
   set_weight(50);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "������ɽ��Ů�嶥�Ĺ���ѩ���Ƴɣ��Ծ���������档\n");
     set("unit", "��");
     set("value", 800);
        set("remaining", 5);
        set("food_supply", 30);
    }
   
   setup();
}

void init()
{
   add_action("do_chi", "eat");
}


int do_chi(string arg)
{

   int heal, recover, sen, e_sen, m_sen,remaining;
   
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ��Ե�̫���ˣ��ٳԾͳ����ˡ�\n");

    this_player()->add("food", (int)query("food_supply"));

    m_sen = (int)this_player()->query("max_sen");
   heal = (int)this_player()->query_con();
    e_sen = (int)this_player()->query("eff_sen");
   
    if ( e_sen < m_sen )
   {    
     if ( (e_sen + heal) >= m_sen )
     {
        this_player()->set("eff_sen", m_sen);
     } else
     {   
        this_player()->add("eff_sen", heal);
     }   
   } 

    e_sen = (int)this_player()->query("eff_sen");
    sen = (int)this_player()->query("sen");
   recover = 30+heal;
    
   if (sen < e_sen )
   {
        if ( (sen + recover) >= e_sen )
        {
            this_player()->set("sen", e_sen);
        } else
        {   
            this_player()->add("sen", recover);
        }   
   }

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
   if ( query("remaining") )
   {
         message_vision("$N����һ���ѩ�������˼��ڡ�һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
   } else 
   { 
         message_vision("$N������Ĺ�ѩ������øɸɾ�������������δ����\n", this_player());
     
     destruct(this_object());
   }

   return 1;
}
