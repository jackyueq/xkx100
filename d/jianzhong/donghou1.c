#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�Ⱥ�����");
	set("long",@LONG
�����������дУ����ﻨ�㣬���ߴ���Ҷ�ķ�϶����
���أ�΢�紵������Ӱһ����涡�����ȫ������һƬ��
ɫ���ڱ��̵ĺ����У��㽥������ʧ�˷���
LONG
	);
	set("exits",([
		"east":__FILE__,
		"west":__FILE__,
		"north":__FILE__,
		"south":__FILE__,
	]));
	set("snake_count",5);
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -420);
	set("coor/z", 0);
	setup();
}
void init()
{
	object ob1,ob2;
	object me=this_player();
	if((random(10)<2)&&(this_object()->query("snake_count")>0)&&(me->query_temp("dugu_visit")!=0)&&(!present("pusi qushe", environment(this_player()))))
	{	
		ob1=new(__DIR__"npc/pusiqushe");
		ob1->move(this_object());
		this_object()->add("snake_count",-1);
	}
}
int valid_leave(object me, string dir)
{
	int i;
	string msg;
	if(!me->query_temp("dugu_visit"))
	{
		if(dir=="north")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>0)&&(i<10)) me->add_temp("zhongnan/tree",-1);
			if((i>9)&&(i<12)) me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="south")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i<4)||(i==14)) 
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="east")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>3)&&(i<10))
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="west")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>11)&&(i<14))
				me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if (me->query_temp("zhongnan/tree") >= 15)
         	{
     	    		me->move(__DIR__"donghou");
           		me->delete_temp("zhongnan/tree");
			message("vision",me->query("name")+"һ�����ݵش����������˳�����\n",environment(me),me);
             		return notify_fail("�����˰��죬�����߳�����Ƭ���֡�\n");
         	} else
		if (me->query_temp("zhongnan/tree") < i)
		{
			message("vision",me->query("name")+"���ҵ���������������ȥ��\n",environment(me),me);
			msg="�����˼������������߽������ֵĸ����\n";
		} else
		if (me->query_temp("zhongnan/tree") == i)
		{
			message("vision",me->query("name")+"��������֣�����һ������߻���ԭ�ء�\n",environment(me),me);
			msg="����������֣�����һ������߻���ԭ�ء�\n";
		} else
		{
			message("vision",me->query("name")+"�ƺ����г��������������\n",environment(me),me);
			msg="�����˼���������������ƺ������߹���\n";
		}
		return notify_fail(msg);//::valid_leave(me,dir);
	}else 
	if (me->query_temp("dugu_visit")==1)
	{	if(dir=="north")
		{
			message("vision",me->query("name")+"���������ȥ����ʧ����֮�С���\n",environment(me),me);
			me->move(__DIR__"qiaobi");
			me->delete_temp("dugu_visit");
			message("vision",me->query("name")+"�����������˹�����\n",environment(me),me);
			return notify_fail("��������������������һ���ͱ�֮ǰ��\n");
		} else
		{
			message_vision("$N���������Ų����У����߱����ͷ羰��\n",me);
			return ::valid_leave(me,dir);
		}
	}
}