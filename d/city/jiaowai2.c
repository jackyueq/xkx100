// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;
#define MAX_EXP 2000

void create()
{
	set("short", "����");
	set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ����
�в������֣�������ת��ʹ���ʱ���⾡����������С��Сȸ����
���ϻ��裬һ��Ҳ�����ˡ������Ǹ�����da���ĺû��ᡣ
    �������˺ܶ���֦ʯ�顣
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai1",
		"south" : __DIR__"jiaowai3",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/qiu-wanjia": 1,
		__DIR__"obj/shuzhi": 1,
		__DIR__"obj/shitou": 1,
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();	
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
        object me;
        int i, kar, cps, add_exp, add_pot, add_score;
        me = this_player();

        if (me->query("combat_exp")>=MAX_EXP)
            return notify_fail("��������Ϸ������С������ɣ�\n");
        
        if(me->is_busy())
             return notify_fail("�㻹�ǵȹ�װ���˼��ٴ���ɣ�\n");

        if(me->query("qi")<10)
             return notify_fail(HIR"��̫���ˣ���������Ϣһ�°ɣ����ҲҪ������Ӵ����\n"NOR);
             

        me->start_busy(3);
        message_vision("$N�����ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n", me);
        message_vision("$Nֻ������һ�����������\n",me);
        kar = random((int)me->query("kar"));
        
        if (kar<=5) 
           {
           	message_vision("$NʲôҲû�򵽡�\n",me ); 
           	          	           	          
            }
        else 
        
           {    
                if (kar>5 && kar<=8) 
                   
                   {
                      message_vision("$N��һֻ"YEL"��ȸ��\n"NOR, me);
                      add_exp=4+random(5);
                      add_pot=4+random(5);  
                   }
                 if (kar>8 && kar<=10) 

                    {
                      message_vision("$N��һֻ"HIG"���ġ�\n"NOR, me);
                      add_exp=6+random(5);
                      add_pot=6+random(5);                 
                     }  
                 if (kar>10 && kar<=15)
                
                   {
                      message_vision("$N��һֻ"HIY"��˿ȸ��\n"NOR, me);                    
                      add_exp=8+random(5);
                      add_pot=8+random(5);   
                    }       
                if (kar >15) 
                
                   {
                      message_vision("$N��һֻ"HIW"������\n"NOR, me);                    
                      add_exp=10+random(5);
                      add_pot=10+random(5);                                                                                                                              
                    }        
                    
                add_score=10+random(5);                               
                
                me->add("combat_exp",add_exp);
                me->add("potential",add_pot);
                me->add("score",add_score);
                tell_object(me,HIW"��õ���:"
                            + chinese_number(add_exp) + "��ʵս���飬"
                            + chinese_number(add_pot) + "��Ǳ�ܣ�"
                            + chinese_number(add_score) + "�㽭��������\n"NOR);

             }                   
         me->receive_damage("qi", 5);
         return 1;      
 }
       