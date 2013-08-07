// Room: /d/nanshaolin/fota2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_wuse();
string look_wuxiang();
string look_kuzhi();
string look_kuhui();
string look_tianming();
string look_huizhi();
void create()
{
	set("short", "ʥɮ��");
	set("long", @LONG
���㹩���������ϴ���λ�е¸�ɮ�����巨̨����������֮�Σ���
������λ���������ּ�������ɫ̨(wuse)�������� (wuxiang)��������
̨(tianming), �����鱮(kuzhi)�������(kuhui)������ʥ��(huizhi)��
   �������͸�������������ڣ��ƺ�Ϊǧ�����������һ�������   
LONG );
	set("exits", ([
		"up"   : __DIR__"fota3", 
		"down" : __DIR__"fota1",       
	]));
	set("item_desc",([
		"wuse"     : (: look_wuse :),
		"wuxiang"  : (: look_wuxiang :),
		"tianming" : (: look_tianming :),
		"kuzhi"    : (: look_kuzhi :),
		"kuhui"    : (: look_kuhui :),
		"huizhi"   : (: look_huizhi :),
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_sheshen","sheshen");
	add_action("do_fushi","fushi");
	add_action("do_chuzhang","chuzhang");
	add_action("do_chuzhang","break");
	add_action("do_shenru","shenru");
	add_action("do_taotuo","taotuo");
	add_action("do_canchan","canchan");
	add_action("do_canchan","buddhism");
	add_action("do_enter","enter");
}

int do_say(string arg)
{
	object me = this_player();
// string dir;
	if (arg=="���մ�ϲ����ȴΣ����")
	{
		write( "��ɫ��ʦ����̨ͻȻ��ת����������¡¡���졣һ������ֱ͸���ĵף����ԸΪ�ҷ�������\n");
		me->set_temp("poem_said",1);
		return 1;   
	}
	if (arg=="���ò���ɢ������ʵ�಻")
	{
		write("���д��ģ��β�ʵʩ��\n");
		me->set_temp("shen_said",1);
		return 1;
	}
	if (arg=="����������")
	{
		write("�������ѹ������ɵô����ۣ��Ŀ��˼��ڤڤ��ֻҪ���Ѵ˵ء�\n");
		me->set_temp("m_said",1);
		return 1;
	} 
}
int do_sheshen()
{
	object me = this_player();
	if(me->query_temp("poem_said"))
	{
		me->delete_temp("poem_said");
		if ((int)me->query_skill("buddhism",1)<30)
		{
			write("�����д��ģ��κη���Ϊ̫������˵��Լ���\n");
			me->unconcious();    
			return 1;
		}
		write( "������е��������������ǣ����������죿������ֱ��̨ײȥ��\nֻ�����顱��һ�������ѱ��ͽ��˷�̨��\n");
		me->move(__DIR__"wusetai");
		tell_room(environment(me),me->name()+"һͷײ�˽�����\n",({me}));
		return 1; 
	}
}
int do_canchan(string arg)
{
	object me = this_player();
	if (arg!="zuo" && arg!="ʥ��")
		return notify_fail("��Ҫ��ʲô��������\n");
	message("vision", me->name()+"���Ŵ�ʦ��ʥ��ڤ˼������\n", environment(me), ({me}) );
	write("��������ĬĬ���С��������÷�����Ըʾ��Ҫ����\n");
	if (random(3)==1)
	{
		write(HIR"��������У��о���ʦ���´���һ��С�š�\n" NOR);
		me->set_temp("marks/��",1);
		return 1;
	}
	return 1;
}  
 
int do_enter()
{
	object me = this_player();
	if ((int)this_player()->query_temp("marks/��")) 
	{
		me->delete_temp("marks/��");
		write("����æ���ַ���С�š�\n");
		if ((int)me->query_skill("hand",1)<30)
		{
			write(HIR"���ַ�̫����С���Ѿ���ʧ����ͷ����ֻ��һƬ���ҡ�\n"NOR);
			me->unconcious(); 
			return 1;
		}
		message("vision", me->name()+"˫�����裬����Ʈ����ͻȻ��ʧ��ʥ�����ˡ�\n", environment(me), ({me}) );
		write(HIR"���С�������˽�ȥ��\n"NOR);
		me->move(__DIR__"huizhizuo");
		tell_room(environment(me), me->name() + "����������\n", ({me}));
		return 1;
	}  
	return 0;
} 

int do_shenru() 
{
	object me = this_player();
	if(me->query_temp("shen_said"))
	{
		me->delete_temp("shen_said");
		write("������һ�ݣ�ʮָ�繳������̨����һץҪ����Ծ��\n");
		message("vision", me->name()+"����һ�ݣ�ʮָ�繳������̨����һץҪ��������\n", environment(me), ({me}) );
		if((int)me->query_skill("claw",1)<30)
		{
			write("����ָ��̨�߲��˴���û��ץ������.....��\n");
			message("vision", me->name()+"��ָ��̨�߻���һ�����룬û��ץ����\n", environment(me), ({me}) );
			message("vision", me->name()+"һ����У�һ�����Դ�ˤ��������\n", environment(me), ({me}) );
			me->unconcious();
			return 1;    
		}
		write( "����̨��һ�������������ֱ�ϣ����������ϣ������һ����ֱˤ����̨��\n");
		message("vision", me->name()+"���ֱ�ϣ����������ϡ�ͻȻ����һ�Σ����ټ����ޡ�\n", environment(me), ({me}) );
		me->move(__DIR__"tianming");
		tell_room(environment(me), me->name() + "ˤ��������\n", ({me}));
		return 1;
	}
	return 0;   
}

int do_taotuo()
{
	object me = this_player();
	if (me->query_temp("m_said"))
	{
		me->delete_temp("m_said");
		message("vision", me->name()+"���������߳�������Ծ��������Ҫ�ӳ���\n", environment(me), ({me}) );
		if ((int)me->query_skill("leg",1)<30)
		{
			write("�������Ѿ���ľ�ˣ������ڵ��ء�\n");
			return 1;
		} 
		message("vision", me->name()+"����һ����ʧ�ڴ��ߡ�\n", environment(me), ({me}) );
		write(HIR "��յ����ߣ�ֻ����ǰһ�ڣ��������ȥ��\n"NOR);
		me->move(__DIR__"kuhuiping");
		tell_room(environment(me), me->name() + "����������\n", ({me}));
		return 1;
	}  
	return 0;
}

int do_fushi(string arg)
{
	object me = this_player();
	if (arg!="pai"&&arg!="��") return notify_fail("��Ҫ����ʲô��\n");
	message("vision", me->name()+"�����������������ȥ������\n", environment(me), ({me}) );
	write("������ط��������ơ�\n");
	if (random(2)==1)
	{
		write(HIR"��ͻȻ��һ�ֳ��Ƶĳ嶯������һ�ƻ�����\n"NOR);
		me->set_temp("marks/��",1); 
	}
	return 1;
}

int do_chuzhang(string arg)      
{
	object me = this_player();     
	if ((int)me->query_temp("marks/��"))
	{
		if(arg!="pai" && arg!="��")
			return notify_fail("��Ҫ�ĳ��ƣ�\n");
		me->delete_temp("marks/��");               
		if ((int)me->query("neili",1)>100)
		{
			write(HIR"�����˵���ٵ�һ���������Ƴ�һ�ơ�ֻ��ž��һ���������ѿ�һ����죬���������϶����ȥ��\n"NOR);
			message("vision", me->name()+"���˵���ٵ�һ���������Ƴ�һ�ơ�ֻ��ž��һ���������ѿ�һ�����\n", environment(me), ({me})); 
			message("vision", me->name()+"���϶ֱ�Խ�ȥ��һ�����죬����������ĺϺ������\n" , environment(me), ({me}));
			me->receive_damage("neili",100);
			me->move(__DIR__"wuxiangpai");
			return 1;
		}
		message("vision", me->name()+"ž���Ƴ�һ�ƣ������������������˵��Լ�\n", environment(me), ({me})); 
		me->set("neili",0);
		return 1;
	}
	return 0;
}
                   
string look_wuse()
{
	return "\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    �������������������裬���������������������\n"
	"    ��������������������������������������������\n"
	"    ����������΢�紵��������ɽ������������������\n"
	"    ��������������������������������������������\n"
	"    �������������մ�ϲ����ȴΣ��������������\n"
	"    ��������������������������������������������\n"
	"    �������������������ǣ����������죿����������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n";
}
string look_wuxiang()
{
	return "\n"
        "    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ������������������̨��  ��������\n"
	"    ��������������������������������\n"
	"    �����������ӽ��ڷ��ã�����������\n"
	"    ��������������������������������\n"
	"    ���������������ǳ���������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n";
}
string look_tianming()
{
	return "\n"
        "    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ����������������Ⱦ�֣�����������\n"
	"    ��������������������������������\n"
	"    �����������ĵ����㲻��  ��������\n"
	"    ��������������������������������\n"
	"    ��������  ���ò���ɢ������������\n"
	"    ��������������������������������\n"
	"    ��������������ʵ�಻������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n";
}
string look_kuhui()
{ 
	return "\n"
        "    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������  �Ͼ������У�  ��������\n"
	"    ��������������������������������\n"
	"    �������������������֣�  ��������\n"
	"    ��������������������������������\n"
	"    ��������  �������ǻۣ�����������\n"
	"    ��������������������������������\n"
	"    �����������Ƿ������ա�����������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n";
}
string look_huizhi()
{
	return "\n"
        "    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������  ��ڿ����ʵ��  ��������\n"
	"    ��������������������������������\n"
	"    �������������ͣ�Ĵ���  ��������\n"
	"    ��������������������������������\n"
	"    ��������  �������÷�������������\n"
	"    ��������������������������������\n"
	"    ������������Ըʾ��Ҫ������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n"
	"    ��������������������������������\n";
}
string look_kuzhi()
{
	return "\n"
 	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    ����������һ�ж����ᣬ������Ե�ϡ�����������\n"
	"    ��������������������������������������������\n"
	"    ��������������б��룬�޳��ѵþá�����������\n"
	"    ��������������������������������������������\n"
	"    ��������������Ϊ��ĸ����ֲ��Ա�������������\n"
	"    ��������������������������������������������\n"
	"    ����������������η�壬��Σ�ڳ�¶������������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n"
	"    ��������������������������������������������\n";
}
