// huaiyun.c
// by angle

#include <ansi.h>
#include <condition.h>
void shengle(object me);
int birth1(object me,object obj);
void birth2(object me,object obj);
object create_baby(object me,object obj);

inherit F_CLEAN_UP;


int update_condition(object me, int duration)
{// 320��heart_beatһ����  
	if ( me->is_fighting() && duration < 2230 && duration > 0 ){
		tell_object(me, HIR "��ͻȻ������Щ������֧����������ر������\n" NOR );
    if (me->query("neili")>200) 
     me->add("neili",-200);
    else
     me->set("neili",0);
	}
	else if ( duration == 2720 || duration == 2700){
		tell_object(me, HIB "��ͻȻ�е�һ��Ķ��ģ��̲�ס��·������һ����������Ǻ�Щ�ˡ�\n" NOR );
	}
	else if (duration ==2560 || duration == 2565 ){
			tell_object(me, HIB "��ͻȻ�е�һ��Ķ��ģ���æ��ס�죬������̲�ס���˳�����\n�ѵ��ϴ�������������\n" NOR );
	}
	else if (duration >=2230 &&  duration <2560 ){
		if (duration%10==1)
			tell_object(me, HIB "����������е㲻������������ֶ��ĵĸо���\n" NOR );
	}
	else if (duration >=1300 && duration <2230 ){
		if (random(20)==1)
	  {
	  	if (me->query("food")>5) me->add("food",-5);
	  	if (me->query("water")>5) me->add("water",-5);
				tell_object(me, HIY "����ö��Ӻܶ�����Ե�ʲô������\n" NOR );
		}else if(random(20)==1)
		{
			if (me->query("jing")>10) me->add("jing",-10);
			if (me->query("qi")>10) me->add("qi",-10);
		  tell_object(me, HIY "��е���Щƣ�������ᱳʹ��ûʲô������\n" NOR );
			}
	}
	else if (duration > 80 && duration < 1300 ){ if (random(50)==1)
			tell_object(me, HIB "�������С�һﲻ���ֵ�������һ�š�\n" NOR );
	}
	else if (duration <= 80 && duration >0){
			if (!environment(me)->query("if_bed"))
			tell_object(me, HIR "��е����ӷ�������������������������ǿ�Ҫ���ˣ���Ѻ��ӵĸ��׽������ؼ����Űɡ�\n" NOR );
			else 	if (!present(me->query("baby/father"),environment(me)))
			tell_object(me, HIY "�����ڴ��ϸо��ö��ˣ��Ͽ�Ѻ��ӵĸ��׽й����ɡ�\n" NOR );
      else if (random(5)==1)
      call_out("shengle",5,me);
			else 
			tell_object(me, HIY "�����ڴ��ϸо��ö��ˣ��ؼ��˾�ʲôҲ�����ˣ������صȴ����ӳ����ɡ�\n" NOR );
	}
	else if (duration == 0 ){
			tell_object(me, RED "��ֻ��������ʹ���̣���������졣�����ܰ����������˰ɡ�����\n" NOR );
		  call_out("shengle",5,me);
  }
	if (duration<2230)
	if (!me->query_temp("apply/attack") || me->query_temp("apply/attack")>=0)
		me->add_temp("apply/attack",-100000);//���͹���
	me->apply_condition("huaiyun", duration - 1);
	return 1;
}
int shengle(object me)
{
	object obj= find_player(me->query("baby/father"));
	if (me->query_temp("apply/attack")<-95000)
	me->add_temp("apply/attack",100000);//�ָ�������
	if( !environment(me)->query("if_bed") )
	{
		message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ������������Ļ���ʵ����̫�����ˣ�\n$N�ĺ��������ˣ��ÿ�������\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
		me->unconcious();
	 } 
	 else if (!obj || !userp(obj) || !present(obj, environment(me)) )
	 {		
		message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ�������ڹؼ�ʱ�̺��ӵĸ���û���غ�������ߣ�\n$N�ĺ��������ˣ��ÿ�������\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
		me->unconcious();
	 } 
	 else
	 {
		me->set_temp("is_bearing",1);
		me->start(100);
		obj->start(100);
		message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me,obj);
		call_out("birth1",15,me,obj);
	 }
   me->clear_condition("huaiyun");
	 return 1;
}

int birth1(object me,object obj)
{  
	 message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
		 "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
	 call_out("birth2",15,me,obj);
	 return 1;
}

void birth2(object me,object obj)
{
	int twins=0;
	object baby1,baby2;
	me->start_busy(1);
	obj->start_busy(1);
	me->set("neili",0);
	me->set("qi",0);
	me->set("jing",0);
	if (!baby1=create_baby(me,obj)) 
		return;
 if (random(30)==1)
 {	
	me->set("baby/gender",random(2)+1);
	if (!baby1=create_baby(me,obj)) 
		return;
 	tell_object(me,"��ϲ��ϲ����λ��������ã���Ȼ��һ��˫��̥��\n");
	tell_object(obj,"��ϲ��ϲ����λ��������ã���Ȼ��һ��˫��̥��\n");
	twins=1;
}	
	message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
		"\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
	me->delete_temp("is_bearing");
	me->delete("baby/father");
	me->delete("baby/gender");
	me->save();
	obj->save();
//this needs to be put at the last since
//can only move the baby after it's parameters are set.
	if(!baby1->move(environment(me)))
	baby1->move(environment(environment(me)));
	if(twins && !baby2->move(environment(me)))
	baby2->move(environment(environment(me)));
	return;
}

object create_baby(object me,object obj)
{
	object baby;
	int number;
	seteuid(getuid());
	if (!baby = new("/d/taohuacun/npc/baby"))
		{
			tell_object(me,"ϵͳ������֪ͨ��ʦ�����\n");
			return 0;
		}
	baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
	me->add("child",1);
	obj->add("child",1);
//	if (random(100)<50)
	if (me->query("baby/gender")==1)
	{		
		baby->set("gender","����");
		baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby" ,obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
		me->set("child_"+me->query("child")+"/id",({baby->query("id"),"baby",obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
		//set(child_1/id,({xiao myname,baby,myname1.wfname1}))
		obj->set("child_"+obj->query("child")+"/id",({baby->query("id"),"baby",obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
	}	else if (me->query("baby/gender")==2)
	{
		baby->set("gender","Ů��");
		baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
		me->set("child_"+me->query("child")+"/id",({baby->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
		obj->set("child_"+obj->query("child")+"/id",({baby->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
	}
	else //wrong data
	{
	message_vision(HIR "$N����������֧�����ˣ�$N�ҽ�һ�����˹�ȥ��\n"NOR, me);
	me->unconcious();
	return 0;
		}
	baby->set("parents",({me->query("id"),obj->query("id")}));
	baby->set("saveid",me->query("id")+me->query("child")+obj->query("id")+obj->query("child"));
	number = me->query("child");
	me->set("child_"+number+"/long",baby->query("long"));
	me->set("child_"+number+"/name",baby->query("name"));
	me->set("child_"+number+"/parents",baby->query("parents"));
	me->set("child_"+number+"/gender",baby->query("gender"));
	me->set("child_"+number+"/saveid",baby->query("saveid"));
	number = obj->query("child");
	obj->set("child_"+number+"/long",baby->query("long"));
	obj->set("child_"+number+"/name",baby->query("name"));
	obj->set("child_"+number+"/parents",baby->query("parents"));
	obj->set("child_"+number+"/gender",baby->query("gender"));
	obj->set("child_"+number+"/saveid",baby->query("saveid"));
	baby->move(environment(me));
	baby->save();
	return baby;
}
